#pragma once

#include "EnTTue/Components/Tags.h"

#include "EnTTinspector/Include.h"

namespace Inspectors::TransformComponents {
	template <typename T>
	class FVectorComponentInspector : public IComponentInspector {
	public:
		T* Component = nullptr;

		bool bIsTransform = true;

		FVectorComponentInspector(FEntityWorld& World, const EEntity Entity) : IComponentInspector(World, Entity) {}

		virtual TSharedPtr<SBorder> CreateWidget() override {
			IComponentInspector::CreateWidget();
			
			Component = World->TryGet<T>(Entity);

			const auto ExpandableArea = SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.FillWidth(0.25f)
				[
					SNew(STextBlock)
					.Text(FText::FromString(FancyName.ToString()))
				]
				+ SHorizontalBox::Slot()
				.FillWidth(.75f)
				[
					SNew(SVectorInputBox)
					.AllowSpin(true)
					.bColorAxisLabels(true)
					.X_Lambda([this] {
						if (!GEditor && !GEditor->IsPlayingSessionInEditor()) { return 0.0; }
						if (!Component) { return 0.0; }
						return Component->X;
					})
					.Y_Lambda([this] {
						if (!GEditor && !GEditor->IsPlayingSessionInEditor()) { return 0.0; }
						if (!Component) { return 0.0; }
						return Component->Y;
					})
					.Z_Lambda([this] {
						if (!GEditor && !GEditor->IsPlayingSessionInEditor()) { return 0.0; }
						if (!Component) { return 0.0; }
						return Component->Z;
					})
					.OnXCommitted_Lambda([this] (float Value, ETextCommit::Type CommitType) {
						if (!GEditor && !GEditor->IsPlayingSessionInEditor()) { return; }
						if (!Component) { return; }
						Component->X = Value;
						
						if (bIsTransform) {
							World->Emplace<FTransformDirtyTag>(Entity);
						}
					})
					.OnYCommitted_Lambda([this] (float Value, ETextCommit::Type CommitType) {
						if (!GEditor && !GEditor->IsPlayingSessionInEditor()) { return; }
						if (!Component) { return; }
						Component->Y = Value;
						
						if (bIsTransform) {
							World->Emplace<FTransformDirtyTag>(Entity);
						}
					})
					.OnZCommitted_Lambda([this] (float Value, ETextCommit::Type CommitType) {
						if (!GEditor && !GEditor->IsPlayingSessionInEditor()) { return; }
						if (!Component) { return; }
						Component->Z = Value;

						if (bIsTransform) {
							World->Emplace<FTransformDirtyTag>(Entity);
						}
					})
				];

			RootWidget->SetContent(ExpandableArea);

			return RootWidget;
		}
	};

	template <typename T>
	class FRotatorComponentInspector : public IComponentInspector {
	public:
		T* Component = nullptr;

		bool bIsTransform = true;

		FRotatorComponentInspector(FEntityWorld& World, const EEntity Entity) : IComponentInspector(World, Entity) {}

		virtual TSharedPtr<SBorder> CreateWidget() override {
			IComponentInspector::CreateWidget();
			
			Component = World->TryGet<T>(Entity);

			const auto ExpandableArea = SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.FillWidth(0.25f)
				[
					SNew(STextBlock)
						.Text(FText::FromString(FancyName.ToString()))
				]
				+ SHorizontalBox::Slot()
				.FillWidth(.75f)
				[
					SNew(SRotatorInputBox)
					.AllowSpin(true)
					.bColorAxisLabels(true)
					.Pitch_Lambda([this] {
						if (!GEditor && !GEditor->IsPlayingSessionInEditor()) { return 0.0; }
						if (!Component) { return 0.0; }
						return Component->Pitch;
					})
					.Yaw_Lambda([this] {
						if (!GEditor && !GEditor->IsPlayingSessionInEditor()) { return 0.0; }
					if (!Component) { return 0.0; }
						return Component->Yaw;
					})
					.Roll_Lambda([this] {
						if (!GEditor && !GEditor->IsPlayingSessionInEditor()) { return 0.0; }
						if (!Component) { return 0.0; }
						return Component->Roll;
					})
					.OnPitchCommitted_Lambda([this] (float Value, ETextCommit::Type CommitType) {
						if (!GEditor && !GEditor->IsPlayingSessionInEditor()) { return; }
						if (!Component) { return; }
						Component->Pitch = Value;

						if (bIsTransform) {
							World->Emplace<FTransformDirtyTag>(Entity);
						}
					})
					.OnYawCommitted_Lambda([this] (float Value, ETextCommit::Type CommitType) {
						if (!GEditor && !GEditor->IsPlayingSessionInEditor()) { return; }
						if (!Component) { return; }
						Component->Yaw = Value;

						if (bIsTransform) {
							World->Emplace<FTransformDirtyTag>(Entity);
						}
					})
					.OnRollCommitted_Lambda([this] (float Value, ETextCommit::Type CommitType) {
						if (!GEditor && !GEditor->IsPlayingSessionInEditor()) { return; }
						if (!Component) { return; }
						Component->Roll = Value;

						if (bIsTransform) {
							World->Emplace<FTransformDirtyTag>(Entity);
						}
					})
				];
		
			RootWidget->SetContent(ExpandableArea);
		
			return RootWidget;
		}
	};
}
