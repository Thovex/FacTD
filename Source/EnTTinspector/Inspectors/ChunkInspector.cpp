#include "ChunkInspector.h"

#include "EnTTue/Components/BaseComponents.h"
#include "EnTTue/Components/TransformComponents.h"

namespace Inspectors::TransformComponents {
    TSharedPtr<SBorder> FChunkComponentInspector::CreateWidget() {
        IComponentInspector::CreateWidget();
        
        ChunkComponent = World->TryGet<FChunkComponent>(Entity);

        TSharedPtr<SGridPanel> Grid;

        const auto ExpandableArea = SNew(SExpandableArea)
        .InitiallyCollapsed(true)
        .HeaderContent()
        [
            SNew(STextBlock)
            .Text(FText::FromString(FancyName.ToString()))
        ]
        .BodyContent()
        [
            SNew(SVerticalBox)
            +SVerticalBox::Slot()
            .AutoHeight()
            [
                SNew(SHorizontalBox)
                + SHorizontalBox::Slot()
                .FillWidth(0.25f)
                [
                    SNew(STextBlock).Text(FText::FromString(TEXT("Chunk Size")))
                ]
                + SHorizontalBox::Slot()
                .FillWidth(0.75f)
                [
                    SNew(SNumericEntryBox<float>)
                    .IsEnabled(false)
                    .AllowSpin(true)
                    .Value_Lambda([this]() {
                        if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return 0.f; }
                        if (!ChunkComponent) { return 0.f; }
                        return ChunkComponent->ChunkSize;
                    })
                ]
            ]
            + SVerticalBox::Slot()
            .AutoHeight()
            [
                SAssignNew(Grid, SGridPanel)
                .FillColumn(0, 1.0f)
                .FillColumn(1, 1.0f)
                .FillColumn(2, 1.0f)
                .FillRow(0, 1.0f)
                .FillRow(1, 1.0f)
                .FillRow(2, 1.0f)
            ]
            + SVerticalBox::Slot()
            .AutoHeight()
            [
                SNew(SListView<FName>)
                .ListItemsSource(&ChunkEntitiesInVicinity)
                .HeaderRow (SNew(SHeaderRow)
                    + SHeaderRow::Column(FName(TEXT("EntitiesInVicinity")))
                    .DefaultLabel(FText::FromString(TEXT("Entities in Vicinity"))))
                .OnGenerateRow_Lambda([](FName Item, const TSharedRef<STableViewBase>& OwnerTable) -> TSharedRef<ITableRow> {
                    return SNew(STableRow<FName>, OwnerTable)
                    [
                        SNew(STextBlock)
                        .Text(FText::FromName(Item))
                    ];
                })
                // .OnRowReleased_Lambda([this](FName Item) {
                //     ChunkEntitiesInVicinity.Remove(Item);
                // })
                .OnMouseButtonClick_Lambda([this](FName Item) {
                   const FRegexPattern Pattern(TEXT("\\(Entity ID: (\\d+),"));
                   FRegexMatcher Matcher(Pattern, Item.ToString());

                   if (Matcher.FindNext()) {
                       const EEntity NewSelectedEntity = static_cast<EEntity>(FCString::Atoi(*Matcher.GetCaptureGroup(1)));
                        
                       if (SelectedEntity == NewSelectedEntity) {
                           SelectedEntity = entt::null;
                       } else {
                           SelectedEntity = NewSelectedEntity;
                       }
                   } 
               })
                .OnItemToString_Debug_Lambda([](FName Item) -> FString {
                    return Item.ToString();
                })
            ]
            + SVerticalBox::Slot()
            .AutoHeight()
            [
                SNew(SListView<FName>)
                .ListItemsSource(&NeighbouringEntitiesInVicinity)
                .HeaderRow (SNew(SHeaderRow)
                    + SHeaderRow::Column(FName(TEXT("NeighbouringEntitiesInVicinity")))
                    .DefaultLabel(FText::FromString(TEXT("Neighbouring Entities in Vicinity"))))
                .OnGenerateRow_Lambda([](FName Item, const TSharedRef<STableViewBase>& OwnerTable) -> TSharedRef<ITableRow> {
                    return SNew(STableRow<FName>, OwnerTable)
                    [
                        SNew(STextBlock)
                        .Text(FText::FromName(Item))
                    ];
                })
                // .OnRowReleased_Lambda([this](FName Item) {
                //     NeighbouringEntitiesInVicinity.Remove(Item);
                // })
                .OnMouseButtonClick_Lambda([this](FName Item) {
                    const FRegexPattern Pattern(TEXT("\\(Entity ID: (\\d+),"));
                    FRegexMatcher Matcher(Pattern, Item.ToString());

                    if (Matcher.FindNext()) {
                        const EEntity NewSelectedEntity = static_cast<EEntity>(FCString::Atoi(*Matcher.GetCaptureGroup(1)));
                        
                        if (SelectedEntity == NewSelectedEntity) {
                            SelectedEntity = entt::null;
                        } else {
                            SelectedEntity = NewSelectedEntity;
                        }
                    } 
                })
                .OnItemToString_Debug_Lambda([](FName Item) -> FString {
                    return Item.ToString();
                })
            ]
        ];

        size_t Index = 0;
        for (int32 x = 0; x <= 2; ++x) {
            for (int32 y = 0; y <= 2; ++y) {
                bool bIsCenter = (x == 1 && y == 1);

                Grid->AddSlot(x, y)
                .Padding(1.f)
                [
                    SNew(SBorder)
                    .BorderBackgroundColor(bIsCenter ? FLinearColor::Green : FLinearColor::White)
                    .Padding(5)
                    [
                        SNew(STextBlock)
                        .Text_Lambda([this, bIsCenter, Index]() -> FText {
                            if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return FText::FromString(TEXT("[/]")); }
                            
                            if (bIsCenter) {
                                return FText::FromString(FString::Printf(TEXT("(%d, %d)"), ChunkComponent->RelevantCell.X, ChunkComponent->RelevantCell.Y));
                            }
                            return FText::FromString(FString::Printf(TEXT("(%d, %d)"), ChunkComponent->NeighbourCells[Index].X, ChunkComponent->NeighbourCells[Index].Y));
                        })
                        .Margin(5)
                        .Justification(ETextJustify::Center)
                        .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Regular.ttf"), 14))
                    ]
                ];

                if (!bIsCenter) ++Index;
            }
        }

        RootWidget->SetContent(ExpandableArea);

        return RootWidget;
    }
    
    void FChunkComponentInspector::Tick(UWorld* WorldRoot, FEntityWorld& EntityWorld, const float DeltaTime) {
        ChunkEntitiesInVicinity.Empty();
        NeighbouringEntitiesInVicinity.Empty();

        if (EntityWorld.Valid(SelectedEntity)) {
            // TODO: AABB Component
            DrawDebugString(WorldRoot, World->GetWorldPosition(Entity), "ROOT", nullptr, FColor::Red, DeltaTime * 2.f, true);
            DrawDebugBox(WorldRoot, World->GetWorldPosition(Entity), FVector(50.f, 50.f, 50.f), FColor::Green, false, DeltaTime * 2.f, 0, 5.0f);

            DrawDebugBox(WorldRoot, World->GetWorldPosition(SelectedEntity), FVector(50.f, 50.f, 50.f), FColor::Red, false, DeltaTime * 2.f, 0, 5.0f);
        }
        
        for (auto&& [OtherEntity, OtherChunk] : EntityWorld.ForEach<FChunkComponent>()) {
            if (Entity == OtherEntity) {
                continue;
            }

            FString OtherName = FString::Printf(TEXT("(Entity ID: %d, Coords: %d, %d): %s"),
                OtherEntity, OtherChunk.RelevantCell.X, OtherChunk.RelevantCell.Y, *EntityWorld.Get<FNameComponent>(OtherEntity).Name.ToString());

            FName OtherNameAsName = FName(*OtherName);

            if (ChunkComponent->RelevantCell == OtherChunk.RelevantCell) {
                if (!ChunkEntitiesInVicinity.Contains(OtherNameAsName)) {
                    ChunkEntitiesInVicinity.Add(OtherNameAsName);
                }
            } else {
                if (ChunkComponent->NeighbourCells.Contains(OtherChunk.RelevantCell)) {
                    if (!NeighbouringEntitiesInVicinity.Contains(OtherNameAsName)) {
                        NeighbouringEntitiesInVicinity.Add(OtherNameAsName);
                    }
                }
            }
        }
    }
}
