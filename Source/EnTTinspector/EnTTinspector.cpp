#include "EnTTinspector/EnTTinspector.h"

#include "EnTTinspector/Inspectors/ChunkInspector.h"
#include "EnTTinspector/Inspectors/CollisionComponentInspectors.h"
#include "EnTTinspector/Inspectors/NameComponentInspector.h"
#include "EnTTinspector/Inspectors/RenderingComponentInspectors.h"
#include "EnTTinspector/Inspectors/TransformComponentInspectors.h"
#include "EnTTinspector/Inspectors/VelocityComponentInspector.h"

#include "EnTTue/Components/BaseComponents.h"
#include "EnTTue/Components/CollisionComponents.h"
#include "EnTTue/Components/RenderingComponents.h"
#include "EnTTue/Components/TransformComponents.h"

TSharedPtr<SVerticalBox> FEnTTinspector::Root = nullptr;
TSharedPtr<SVerticalBox> FEnTTinspector::DebugInfo = nullptr;

TSet<FName> FEnTTinspector::IgnoredInspectors = {};
TMap<FName, TFunction<TSharedRef<IComponentInspector>(FEntityWorld&, EEntity Entity)>> FEnTTinspector::RegisteredInspectors = {};

bool FEnTTinspector::bInitialized = false;

TSharedRef<SDockTab> CreateOutlinerTab(FSpawnTabArgs const& SpawnArgs)
{
    return SNew(SDockTab)
    .TabRole(NomadTab)
    [
        SNew(SScrollBox)
        + SScrollBox::Slot() [
            SAssignNew(FEnTTinspector::Root, SVerticalBox)  // Wrap everything in a vertical box
            + SVerticalBox::Slot()
            .AutoHeight()
            [
                SAssignNew(FEnTTinspector::DebugInfo, SVerticalBox)
            ]
        ]
    ];
}

UEnTTueGameInstance* CanProceed() {
    if (!GEditor) {
        return nullptr;
    }

    const auto PlayWorld = GEditor->PlayWorld;
    if (!PlayWorld) {
        return nullptr;
    }

    UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(PlayWorld);
    if (!GameInstance) {
        return nullptr;
    }

    UEnTTueGameInstance* EnTTGameInstance = Cast<UEnTTueGameInstance>(GameInstance);
    return EnTTGameInstance;
}

void FEnTTinspector::DestroyEntity(FRegistry& Registry, EEntity Entity) {
    if (const FInspectorComponent* InspectorComp = Registry.try_get<FInspectorComponent>(Entity)) {
        InspectorComp->Owner->RemoveSlot(InspectorComp->RootBorder.ToSharedRef());
    }
}

bool FEnTTinspector::InspectorTick(float DeltaTime) {
    if (!Root) {
        return true;
    }
    
    UEnTTueGameInstance* Inst = CanProceed();
    if (!Inst) {
        Root->ClearChildren();
        RegisteredInspectors.Empty();
        bInitialized = false;
        return true;
    }

    FEntityWorld& World = Inst->GetEntityWorld();

    if (!bInitialized) {
        bInitialized = true;
        UE_LOG(LogTemp, Warning, TEXT("Initializing Entity Inspector"));

        REGISTER_INSPECTOR(FNameComponent, Inspectors::BaseComponents::FNameComponentInspector);

        REGISTER_INSPECTOR(FPositionComponent, Inspectors::TransformComponents::FVectorComponentInspector<FPositionComponent>);
        REGISTER_INSPECTOR(FRotationComponent, Inspectors::TransformComponents::FRotatorComponentInspector<FRotationComponent>);
        REGISTER_INSPECTOR(FScaleComponent, Inspectors::TransformComponents::FVectorComponentInspector<FScaleComponent>);

        REGISTER_INSPECTOR(FSkMeshComponent, Inspectors::RenderingComponents::FSkinnedMeshComponentInspector);
        REGISTER_INSPECTOR(FHismMeshComponent, Inspectors::RenderingComponents::FHismMeshComponentInspector);
        
        REGISTER_INSPECTOR(FVelocityComponent, Inspectors::TransformComponents::FVelocityComponentInspector);
        
        REGISTER_INSPECTOR(FBoxCollisionComponent, Inspectors::CollisionComponents::FBoxCollisionComponentInspector);

        REGISTER_INSPECTOR(FChunkComponent, Inspectors::TransformComponents::FChunkComponentInspector);

        Inst->RegisterInspectors(RegisteredInspectors);

        IGNORE_COMPONENT(FInspectorComponent);
        IGNORE_COMPONENT(FLastPositionComponent);
        IGNORE_COMPONENT(FLastRotationComponent);
        IGNORE_COMPONENT(FLastScaleComponent);
        IGNORE_COMPONENT(FChildrenComponent);
        IGNORE_COMPONENT(FParentComponent);

        Root->AddSlot()
            .AutoHeight()
        [
            SNew(SVerticalBox)
            + SVerticalBox::Slot()
            .AutoHeight()
            [
                SNew(STextBlock)
                 .Text_Lambda([World = &World]() -> FText {
                     return FText::FromString(FString::Printf(TEXT("Entities: %llu"), World->Registry.storage<EEntity>().size()));
                 })
            ]
            + SVerticalBox::Slot()
            .AutoHeight()
            [
                SNew(SButton)
                .Text(FText::FromString("Save"))
                .OnClicked_Lambda([World = &World]() -> FReply {
                    World->Save();
                    return FReply::Handled();
                })
            ]
            + SVerticalBox::Slot()
            .AutoHeight()
            [
                SNew(SButton)
                .Text(FText::FromString("Load"))
                .OnClicked_Lambda([World = &World]() -> FReply {
                    World->Load();
                    return FReply::Handled();
                })
            ]
        ];

        World.OnConstruct<FDestroyAtEndOfTickTag>().connect<&FEnTTinspector::DestroyEntity>(this);
    }

    // Only Process 1st element per frame to prevent lag rofl.
    int32 Count = 0;
    for (auto&& [Entity, NameComp] : World.ForEach<FNameComponent>(entt::exclude<FInspectorInitializedTag, FHiddenInInspectorTag>)) {
        if (Count > 1)
        {
            break;
        }
        
        const FParentComponent* ParentComponent = World.TryGet<FParentComponent>(Entity);
        FChildrenComponent* ChildrenComponent = World.TryGet<FChildrenComponent>(Entity);

        if (ParentComponent && World.Valid(ParentComponent->Parent)) {
            if (!World.AllOf<FInspectorComponent>(ParentComponent->Parent)) {
                // Wait until Parent has finished initializing
                continue;
            }
        }

        FInspectorComponent& InspectorComp = World.Emplace<FInspectorComponent>(Entity);
        World.Emplace<FInspectorInitializedTag>(Entity);

        Count++;

        SAssignNew(InspectorComp.Root, SExpandableArea)
        .InitiallyCollapsed(true)
        .BorderBackgroundColor(FLinearColor::Gray)
        .HeaderContent()
        [
            SNew(STextBlock)
                .Text_Lambda([&World, Entity]() -> FText {
				    if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return FText::FromString(FString(TEXT("Not Playing"))); }
                    if (!World.Valid(Entity)) { return FText::FromString("Unknown"); }
                    if (!World.TryGet<FNameComponent>(Entity)) { return FText::FromString("Unknown"); }
                    return FText::FromString(FString::Printf(TEXT("[%d]: %s"), static_cast<uint32>(Entity), *World.Get<FNameComponent>(Entity).Name.ToString()));
                })
                .Margin(5)
                .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Regular.ttf"), 14))
        ]
        .BodyContent()
        [
            SNew(SVerticalBox) // Main Container
             + SVerticalBox::Slot()
                .Padding(2)
                .AutoHeight()
                [
                    SNew(SExpandableArea)
                    .InitiallyCollapsed(true)
                    .HeaderContent()
                    [
                        SNew(STextBlock)
                            .Text(FText::FromString("World Transform"))
                    ]
                    .BodyContent()
                    [
                        SNew(SVerticalBox)
                        + SVerticalBox::Slot()
                        .AutoHeight()
                        [
                            SNew(SHorizontalBox)
                            + SHorizontalBox::Slot()
                            .FillWidth(0.25f)
                            [
                                SNew(STextBlock)
                                    .Text(FText::FromString(TEXT("World Position")))
                                ]
                            + SHorizontalBox::Slot()
                            [
                                SNew(SNumericVectorInputBox<double>)
                                .bColorAxisLabels(true)
                                .Vector_Lambda([&World, Entity]() -> FVector {
                                    if (!GEditor || !GEditor->IsPlayingSessionInEditor()) {
                                        return FVector::ZeroVector;
                                    }
                                    
                                    if (!World.Valid(Entity)) {
                                        return FVector::ZeroVector;
                                    }

                                    return World.GetWorldPosition(Entity);
                                })
                            ]
                        ]
                        + SVerticalBox::Slot()
                        .AutoHeight()
                        [
                            SNew(SHorizontalBox)
                           + SHorizontalBox::Slot()
                           .FillWidth(0.25f)
                               [
                                   SNew(STextBlock)
                                       .Text(FText::FromString(TEXT("World Rotation")))
                                   ]
                               + SHorizontalBox::Slot()
                               [
                                SNew(SNumericRotatorInputBox<double>)
                                .bColorAxisLabels(true)
                                .Pitch_Lambda([&World, Entity]() -> double {
                                    if (!GEditor || !GEditor->IsPlayingSessionInEditor()) {
                                        return 0.0;
                                    }
                                    
                                    if (!World.Valid(Entity)) {
                                        return 0.0;
                                    }
                                    return World.GetWorldRotation(Entity).Pitch;
                                })
                                .Yaw_Lambda([&World, Entity]() -> double {
                                    if (!GEditor || !GEditor->IsPlayingSessionInEditor()) {
                                        return 0.0;
                                    }
                                    
                                    if (!World.Valid(Entity)) {
                                        return 0.0;
                                    }
                                    return World.GetWorldRotation(Entity).Yaw;
                                })
                                .Roll_Lambda([&World, Entity]() -> double {
                                    if (!GEditor || !GEditor->IsPlayingSessionInEditor()) {
                                        return 0.0;
                                    }
                                    
                                    if (!World.Valid(Entity)) {
                                        return 0.0;
                                    }
                                    return World.GetWorldRotation(Entity).Roll;
                                })
                            ]
                        ]
                        + SVerticalBox::Slot()
                        .AutoHeight()
                        [
                            SNew(SHorizontalBox)
                               + SHorizontalBox::Slot()
                               .FillWidth(0.25f)
                               [
                               SNew(STextBlock)
                                   .Text(FText::FromString(TEXT("World Scale")))
                               ]
                               + SHorizontalBox::Slot()
                               [
                                SNew(SNumericVectorInputBox<double>)
                                .bColorAxisLabels(true)
                                .Vector_Lambda([&World, Entity]() -> FVector {
                                    if (!GEditor || !GEditor->IsPlayingSessionInEditor()) {
                                        return FVector::ZeroVector;
                                    }
                                    
                                    if (!World.Valid(Entity)) {
                                        return FVector::ZeroVector;
                                    }

                                    return World.GetWorldScale(Entity);
                                })
                            ]
                        ]
                    ]
                ]
            + SVerticalBox::Slot()
            .AutoHeight()
            [
                SAssignNew(InspectorComp.InspectorBox, SVerticalBox)
                + SVerticalBox::Slot()
                .Padding(2)
                .AutoHeight()
                [
                SNew(SButton)
                    .Text_Lambda([World = &World, Entity]() -> FText {
                        if (!World) { return FText::FromString("Unknown"); }
                        if (!World->Valid(Entity)) { return FText::FromString("Unknown"); }
                        return World->AllOf<FDrawDebugTag>(Entity) ? FText::FromString("Hide Debug") : FText::FromString("Show Debug");
                    })
                    .OnClicked_Lambda([World = &World, Entity]() -> FReply
                    {
                        if (World)
                        {
                            if (World->Valid(Entity))
                            {
                                if (World->AllOf<FDrawDebugTag>(Entity)) {
                                    World->Erase<FDrawDebugTag>(Entity);
                                } else {
                                    World->Emplace<FDrawDebugTag>(Entity);
                                }
                            }
                        }
                        return FReply::Handled();
                    })
                ]
                + SVerticalBox::Slot()
                .Padding(2)
                .AutoHeight()
                [
                    SNew(SExpandableArea)
                    .InitiallyCollapsed(true)
                    .HeaderContent()
                    [
                        SNew(STextBlock)
                            .Text(FText::FromString("Tags"))
                    ]
                    .BodyContent()
                    [
                        SAssignNew(InspectorComp.TagBox, SVerticalBox)
                    ]
                ]
            ]
            + SVerticalBox::Slot()
            .AutoHeight()
            [
                SNew(SVerticalBox)
                + SVerticalBox::Slot()
                .Padding(2)
                .AutoHeight()
                [
                    SNew(SExpandableArea)
                    .InitiallyCollapsed(true)
                    .Visibility_Lambda([ChildrenComponent]() -> EVisibility {
                        if (!GEditor || !GEditor->IsPlayingSessionInEditor()) {
                            return EVisibility::Collapsed;
                        }
                        
                        if (ChildrenComponent && ChildrenComponent->Children.Num() > 0) {
                            return EVisibility::Visible;
                        }
                        return EVisibility::Collapsed;
                    })
                    .HeaderContent()
                    [
                        SNew(STextBlock)
                            .Text(FText::FromString("Children"))
                    ]
                    .BodyContent()
                    [
                        SAssignNew(InspectorComp.ChildBox, SVerticalBox)
                    ]
                ]
            ]
        ]
        .OnAreaExpansionChanged_Lambda([&](bool bIsExpanded) {
            if (bIsExpanded) {
                InspectorComp.Root->SetBorderBackgroundColor(FLinearColor::Green);
                World.EmplaceOrReplace<FInspectorActiveTag>(Entity);
            } else {
                InspectorComp.Root->SetBorderBackgroundColor(FLinearColor::Gray);
                World.Remove<FInspectorActiveTag>(Entity);
            }
        });

        TSharedPtr<SVerticalBox> ChildParent = nullptr;
        if (ParentComponent && World.Valid(ParentComponent->Parent)) {
            const FInspectorComponent& ParentInspector = World.Get<FInspectorComponent>(ParentComponent->Parent);
            ChildParent = ParentInspector.ChildBox;
        } 

        SVerticalBox::FSlot::FSlotArguments& Slot = ((ChildParent == nullptr) ? Root : ChildParent)->AddSlot()
        .AutoHeight()
        .Padding(2, 2, 2, 2)
        [
            SAssignNew(InspectorComp.RootBorder, SBorder)
            .BorderBackgroundColor(FLinearColor::Gray)
            .BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
            .Padding(5)
            .Content() [
                InspectorComp.Root.ToSharedRef()
            ]
        ];

        InspectorComp.Owner = ((ChildParent == nullptr) ? Root : ChildParent);

        World.Emplace<FInspectorUpdateTag>(Entity);
    }
    
    for (auto&& [Entity, InspectorComp] : World.ForEach<FInspectorComponent, FInspectorUpdateTag>()) {
        World.VisitComponents(Entity, [&] (const entt::type_info& Info) {
            const FName InspectorName = CommonUtil::ComponentTypeInfoToName(Info);
            
            if (InspectorName.ToString().EndsWith("Tag")) {
               InspectorComp.TagBox->AddSlot()
                .AutoHeight()
                [
                    SNew(STextBlock)
                        .Text(FText::FromString(FString::Printf(TEXT("- %s"), *InspectorName.ToString())))
                ];
                return;
            }

            if (IgnoredInspectors.Contains(InspectorName)) {
                return;
            }

            if (RegisteredInspectors.Contains(InspectorName)) {
                const TSharedPtr<IComponentInspector> Inspector = RegisteredInspectors[InspectorName](World, Entity);
                Inspector->FancyName = InspectorName;

                // Add New Inspector
                InspectorComp.InspectorBox->AddSlot()
                .AutoHeight()
                [
                    Inspector->CreateWidget().ToSharedRef()
                ];
                
                InspectorComp.Inspectors.Add(InspectorName, Inspector);
            } else {
                // Default Inspector
                InspectorComp.InspectorBox->AddSlot()
                    .AutoHeight()
                [
                    SNew(STextBlock)
                        .Text(FText::FromString(FString::Printf(TEXT("(WIP) %s"), *InspectorName.ToString())))
                ];
                InspectorComp.Inspectors.Add(InspectorName, nullptr);
            }
        });
        
        World.Erase<FInspectorUpdateTag>(Entity);
    }

    for (auto&& [Entity, InspectorComp] : World.ForEach<FInspectorComponent>()) {
        for (auto&& [InspectorName, Inspector] : InspectorComp.Inspectors) {
            if (!Inspector) {
                continue;
            }

            if (Inspector->RootWidget.IsValid() && Inspector->RootWidget->IsEnabled()) {
                Inspector->Tick( GEditor->PlayWorld, World, DeltaTime);
            }
        }
    }
    
    return true;
}

void FEnTTinspector::StartupModule()
{
    FGlobalTabmanager::Get()->RegisterNomadTabSpawner("Entity Inspector", FOnSpawnTab::CreateStatic(&CreateOutlinerTab))
        .SetDisplayName(NSLOCTEXT("Entity Inspector", "TabTitle", "Entity Inspector"));

    TickDelegateHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateRaw(this, &FEnTTinspector::InspectorTick));
}

void FEnTTinspector::ShutdownModule()
{
    FGlobalTabmanager::Get()->UnregisterNomadTabSpawner("Entity Inspector");
    FTSTicker::GetCoreTicker().RemoveTicker(TickDelegateHandle);
}

IMPLEMENT_MODULE(FEnTTinspector, EnTTinspector)
