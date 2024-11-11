#include "EnTTinspector/Inspectors/NameComponentInspector.h"

#include "EnTTue/Components/BaseComponents.h"

namespace Inspectors::BaseComponents {
	TSharedPtr<SBorder> FNameComponentInspector::CreateWidget() {
		IComponentInspector::CreateWidget();
		
		NameComponent = World->TryGet<FNameComponent>(Entity);

		const auto ExpandableArea = SNew(SExpandableArea)
		.InitiallyCollapsed(true)
		.HeaderContent()
		[
			SNew(STextBlock)
				.Text(FText::FromString(FancyName.ToString()))
		]
		.BodyContent()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			[
				SNew(SEditableText)
				.Text_Lambda([this]() {
					if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return FText::GetEmpty(); }
					if (!NameComponent) { return FText::GetEmpty(); }
					return FText::FromName(NameComponent->Name);
				})
				.OnTextCommitted_Lambda([this](const FText& Text, ETextCommit::Type CommitType) {
					if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return; }
					if (!NameComponent) { return; }
					NameComponent->Name = FName(*Text.ToString());
				})
			]
		];

		RootWidget->SetContent(ExpandableArea);

		return RootWidget;
	}
}
