#include "EnTTinspector/Inspectors/VelocityComponentInspector.h"

namespace Inspectors::TransformComponents {

	TSharedPtr<SBorder> FVelocityComponentInspector::CreateWidget() {
		IComponentInspector::CreateWidget();
		
		VelocityComponent = World->TryGet<FVelocityComponent>(Entity);
	
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
			+ SVerticalBox::Slot()
			.AutoHeight() [
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.FillWidth(0.25f)
				[
					SNew(STextBlock)
						.Text(FText::FromString(TEXT("Delta")))
				]
				+ SHorizontalBox::Slot()
				.FillWidth(0.75f)
				[
					SNew(SVectorInputBox)
						.AllowSpin(true)
						.bColorAxisLabels(true)
						.X_Lambda([this] {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return 0.0; }
							if (!VelocityComponent) { return 0.0; }
							return VelocityComponent->Delta.X;
						})
						.Y_Lambda([this] {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return 0.0; }
							if (!VelocityComponent) { return 0.0; }
							return VelocityComponent->Delta.Y;
						})
						.Z_Lambda([this] {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return 0.0; }
							if (!VelocityComponent) { return 0.0; }
							return VelocityComponent->Delta.Z;
						})
						.OnXCommitted_Lambda([this] (float Value, ETextCommit::Type CommitType) {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return; }
							if (!VelocityComponent) { return; }
							VelocityComponent->Delta.X = Value;
						})
						.OnYCommitted_Lambda([this] (float Value, ETextCommit::Type CommitType) {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return; }
							if (!VelocityComponent) { return; }
							VelocityComponent->Delta.Y = Value;
						})
						.OnZCommitted_Lambda([this] (float Value, ETextCommit::Type CommitType) {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return; }
							if (!VelocityComponent) { return; }
							VelocityComponent->Delta.Z = Value;
						})
					]
				]
			+ SVerticalBox::Slot()
			.AutoHeight() [
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.FillWidth(0.25f)
				[
					SNew(STextBlock)
						.Text(FText::FromString(TEXT("Friction")))
					]
				+ SHorizontalBox::Slot()
				.FillWidth(0.75f)
				[
					SNew(SNumericEntryBox<float>)
						.AllowSpin(true)
						.Value_Lambda([this]() {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return 0.f; }
							if (!VelocityComponent) { return 0.f; }
							return VelocityComponent->Friction;
						})
						.OnValueCommitted_Lambda([this](float NewValue, ETextCommit::Type CommitType) {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return; }
							if (!VelocityComponent) { return; }
							VelocityComponent->Friction = NewValue;
						})
					]
				]
		];
	
		RootWidget->SetContent(ExpandableArea);
	
		return RootWidget;
	}
}
