#include "EnTTinspector/Inspectors/CollisionComponentInspectors.h"

#include "EnTTue/Components/CollisionComponents.h"
#include "EnTTue/UnrealFrameworks/Collision/EnTTueBoxCollision.h"

#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"

namespace Inspectors::CollisionComponents {
	TSharedPtr<SBorder> FBoxCollisionComponentInspector::CreateWidget() {
		IComponentInspector::CreateWidget();

		BoxCollisionComponent = World->TryGet<FBoxCollisionComponent>(Entity);
		
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
					SNew(SButton)
					.OnClicked_Lambda([this]() {
						bVisualizeCollision = !bVisualizeCollision;
						return FReply::Handled();
					})
					[
						SNew(STextBlock)
						.Text_Lambda([this]() {
							return bVisualizeCollision ? FText::FromString(TEXT("Hide Collision")) : FText::FromString(TEXT("Show Collision"));
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
						.Text(FText::FromString(TEXT("Collision Profile: ")))
					]
					+ SHorizontalBox::Slot()
					.FillWidth(0.75f)
					[
						SNew(SComboBox<FName>)
						.OptionsSource(&CollisionProfileNames)
						.OnGenerateWidget(SComboBox<FName>::FOnGenerateWidget::CreateLambda([](FName Item)->TSharedRef<SWidget>
						{
							return SNew(STextBlock)
								.Text(FText::FromName(Item));
						}))
						.OnSelectionChanged_Lambda([this](FName Item, ESelectInfo::Type SelectInfo) {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return; }
							if (!BoxCollisionComponent) { return; }
							BoxCollisionComponent->CollisionProfile = Item;
							GetBox()->SetCollisionProfileName(Item);
						})
						.InitiallySelectedItem(SComboBox<FName>::NullableOptionType(BoxCollisionComponent->CollisionProfile))
						[
							SNew(STextBlock)
							.Text_Lambda([this]() {
								if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return FText::GetEmpty(); }
								if (!BoxCollisionComponent) { return FText::GetEmpty(); }
								return FText::FromName(BoxCollisionComponent->CollisionProfile);
							})
						]
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
						.Text(FText::FromString(TEXT("Offset: ")))
					]
					+ SHorizontalBox::Slot()
					.FillWidth(0.75f)
					[
						SNew(SVectorInputBox)
						.AllowSpin(true)
						.bColorAxisLabels(true)
						.X_Lambda([this] {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return 0.0; }
							if (!BoxCollisionComponent) { return 0.0; }
							return BoxCollisionComponent->Offset.X;
						})
						.Y_Lambda([this] {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return 0.0; }
							if (!BoxCollisionComponent) { return 0.0; }
							return BoxCollisionComponent->Offset.Y;
						})
						.Z_Lambda([this] {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return 0.0; }
							if (!BoxCollisionComponent) { return 0.0; }
							return BoxCollisionComponent->Offset.Z;
						})
						.OnXCommitted_Lambda([this](float Value, ETextCommit::Type CommitType) {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return; }
							if (!BoxCollisionComponent) { return; }
							BoxCollisionComponent->Offset.X = Value;
							GetBox()->SetWorldLocation(World->GetWorldPosition(Entity) + BoxCollisionComponent->Offset);
						})
						.OnYCommitted_Lambda([this](float Value, ETextCommit::Type CommitType) {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return; }
							if (!BoxCollisionComponent) { return; }
							BoxCollisionComponent->Offset.Y = Value;
							GetBox()->SetWorldLocation(World->GetWorldPosition(Entity) + BoxCollisionComponent->Offset);
						})
						.OnZCommitted_Lambda([this](float Value, ETextCommit::Type CommitType) {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return; }
							if (!BoxCollisionComponent) { return; }
							BoxCollisionComponent->Offset.Z = Value;
							GetBox()->SetWorldLocation(World->GetWorldPosition(Entity) + BoxCollisionComponent->Offset);
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
						.Text(FText::FromString(TEXT("Extents: ")))
					]
					+ SHorizontalBox::Slot()
					.FillWidth(0.75f)
					[
						SNew(SVectorInputBox)
						.AllowSpin(true)
						.bColorAxisLabels(true)
						.X_Lambda([this] {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return 0.0; }
							if (!BoxCollisionComponent) { return 0.0; }
							return BoxCollisionComponent->Extents.X;
						})
						.Y_Lambda([this] {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return 0.0; }
							if (!BoxCollisionComponent) { return 0.0; }
							return BoxCollisionComponent->Extents.Y;
						})
						.Z_Lambda([this] {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return 0.0; }
							if (!BoxCollisionComponent) { return 0.0; }
							return BoxCollisionComponent->Extents.Z;
						})
						.OnXCommitted_Lambda([this](float Value, ETextCommit::Type CommitType) {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return; }
							if (!BoxCollisionComponent) { return; }
							BoxCollisionComponent->Extents.X = Value;
							GetBox()->SetBoxExtent(BoxCollisionComponent->Extents, true);
						})
						.OnYCommitted_Lambda([this](float Value, ETextCommit::Type CommitType) {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return; }
							if (!BoxCollisionComponent) { return; }
							BoxCollisionComponent->Extents.Y = Value;
							GetBox()->SetBoxExtent(BoxCollisionComponent->Extents, true);
						})
						.OnZCommitted_Lambda([this](float Value, ETextCommit::Type CommitType) {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return; }
							if (!BoxCollisionComponent) { return; }
							BoxCollisionComponent->Extents.Z = Value;
							GetBox()->SetBoxExtent(BoxCollisionComponent->Extents, true);
						})
					]
				]
			];

		RootWidget->SetContent(ExpandableArea);

		return RootWidget;
	}
	
	void FBoxCollisionComponentInspector::Tick(UWorld* WorldRoot, FEntityWorld& EntityWorld, const float DeltaTime) {
		if (!bVisualizeCollision) { return; }
		DrawDebugBox(WorldRoot->GetWorld(),
			EntityWorld.GetWorldPosition(Entity) + BoxCollisionComponent->Offset,
			BoxCollisionComponent->Extents,
			FColor::Red, false, DeltaTime * 2.f, 0, 5.0f);

		DrawDebugBox(WorldRoot->GetWorld(),
			BoxCollisionComponent->CollisionActor->GetShape()->GetComponentLocation(),
			BoxCollisionComponent->Extents * 0.95f, 
			FColor::Green, false, DeltaTime * 2.f, 0, 5.0f);
	}

	UBoxComponent* FBoxCollisionComponentInspector::GetBox() {
		if (!BoxCollisionComponent) { return nullptr; }
		if (!BoxCollisionComponent->CollisionActor) { return nullptr; }
		const AEnTTueBoxCollision* EnTTueBoxCollision = static_cast<AEnTTueBoxCollision*>(BoxCollisionComponent->CollisionActor);
		if (!EnTTueBoxCollision) { return nullptr; }
		return EnTTueBoxCollision->BoxCollision;
	}
	
}
