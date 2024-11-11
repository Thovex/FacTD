#include "EnTTinspector/Inspectors/RenderingComponentInspectors.h"

#include "EnTTue/Components/RenderingComponents.h"
#include "EnTTue/Components/Tags.h"

#include "Engine/SkeletalMesh.h"
#include "Engine/StaticMesh.h"

namespace Inspectors::RenderingComponents {
	TSharedPtr<SBorder> FSkinnedMeshComponentInspector::CreateWidget() {
		IComponentInspector::CreateWidget();
		
		SkinnedMeshComponent = World->Registry.try_get<FSkMeshComponent>(Entity);

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
				.AutoHeight()
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(STextBlock)
						.Text(FText::FromString(TEXT("Mesh")))
					]
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						CreateMeshPropertyWidget()
					]
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(STextBlock)
						.Text_Lambda([this] {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return FText::GetEmpty(); }
							if (!SkinnedMeshComponent) { return FText::GetEmpty(); }
							return FText::FromString(TEXT("Materials (") + FString::FromInt(SkinnedMeshComponent->Materials.Num()) + TEXT(")"));
						})
					]
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						CreateMaterialsWidget()
					]
				]
				// ...
			];

		RootWidget->SetContent(ExpandableArea);

		return RootWidget;
	}
	void FSkinnedMeshComponentInspector::OnMeshChanged(const FAssetData& AssetData) {
		USkeletalMesh* Mesh = Cast<USkeletalMesh>(AssetData.GetAsset());

		World->Emplace<FResourceRestoreTag>(Entity);

		World->Remove<FBakedAnimationsTag>(Entity);
		World->Remove<FResourceLoadedTag>(Entity);

		World->Patch<FSkMeshComponent>(Entity, [&](FSkMeshComponent& Component) {
			Component.Mesh = Mesh;
		});
	}
	
	void FSkinnedMeshComponentInspector::OnMaterialChanged(int32 Index, const FAssetData& AssetData) {
		World->Emplace<FResourceRestoreTag>(Entity);

		World->Remove<FBakedAnimationsTag>(Entity);
		World->Remove<FResourceLoadedTag>(Entity);

		World->Patch<FSkMeshComponent>(Entity, [&](FSkMeshComponent& Component) {
			Component.Materials[Index] = Cast<UMaterialInterface>(AssetData.GetAsset());
		});
	}

	TSharedRef<SWidget> FSkinnedMeshComponentInspector::CreateMeshPropertyWidget() {
		return SNew(SObjectPropertyEntryBox)
		.AllowedClass(USkeletalMesh::StaticClass())
		.ObjectPath_Lambda([this]() {
			if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return FString(TEXT("Not Playing")); }
			if (!SkinnedMeshComponent) { return FString(TEXT("No Skinned Mesh Component")); }
			if (!SkinnedMeshComponent->Mesh) { return FString(TEXT("No Mesh")); }
			return FAssetData(SkinnedMeshComponent->Mesh).GetExportTextName();
		})
		.OnObjectChanged_Lambda([this](const FAssetData& AssetData) {
			if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return; }
			OnMeshChanged(AssetData);
		});
	}

	TSharedRef<SWidget> FSkinnedMeshComponentInspector::CreateMaterialsWidget() {
		TSharedRef<SVerticalBox> MaterialsBox = SNew(SVerticalBox);

		for (int32 Index = 0; Index < SkinnedMeshComponent->Materials.Num(); ++Index) {
			MaterialsBox->AddSlot()
			.AutoHeight()
			[
				SNew(SObjectPropertyEntryBox)
				.AllowedClass(UMaterialInterface::StaticClass())
				.ObjectPath_Lambda([this, Index]() {
					if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return FString(TEXT("Not Playing")); }
					if (!SkinnedMeshComponent) { return FString(TEXT("No Skinned Mesh Component")); }
					if (Index >= SkinnedMeshComponent->Materials.Num()) { return FString(TEXT("Invalid Index")); }
					if (!SkinnedMeshComponent->Materials[Index]) { return FString(TEXT("No Material"));}
					return FAssetData(SkinnedMeshComponent->Materials[Index]).GetExportTextName();
				})
				.OnObjectChanged_Lambda([this, Index](const FAssetData& AssetData) {
					if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return; }
					OnMaterialChanged(Index, AssetData);
				})
			];
		}

		return MaterialsBox;
	}
	
	TSharedPtr<SBorder> FHismMeshComponentInspector::CreateWidget() {
		IComponentInspector::CreateWidget();
		
		HismMeshComponent = World->Registry.try_get<FHismMeshComponent>(Entity);

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
				.AutoHeight()
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(STextBlock)
						.Text(FText::FromString(TEXT("Mesh")))
					]
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						CreateMeshPropertyWidget()
					]
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(STextBlock)
						.Text_Lambda([this] {
							if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return FText::GetEmpty(); }
							if (!HismMeshComponent) { return FText::GetEmpty(); }
							return FText::FromString(TEXT("Materials (") + FString::FromInt(HismMeshComponent->Materials.Num()) + TEXT(")"));
						})
					]
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						CreateMaterialsWidget()
					]
				]
				// ...
			];

		RootWidget->SetContent(ExpandableArea);

		return RootWidget;
	}
	
	void FHismMeshComponentInspector::OnMeshChanged(const FAssetData& AssetData) {
		UStaticMesh* Mesh = Cast<UStaticMesh>(AssetData.GetAsset());

		World->Emplace<FResourceRestoreTag>(Entity);

		World->Remove<FBakedAnimationsTag>(Entity);
		World->Remove<FResourceLoadedTag>(Entity);

		World->Patch<FHismMeshComponent>(Entity, [&](FHismMeshComponent& Component) {
			Component.Mesh = Mesh;
		});
	}
	
	void FHismMeshComponentInspector::OnMaterialChanged(int32 Index, const FAssetData& AssetData) {
		World->Emplace<FResourceRestoreTag>(Entity);

		World->Remove<FBakedAnimationsTag>(Entity);
		World->Remove<FResourceLoadedTag>(Entity);

		World->Patch<FHismMeshComponent>(Entity, [&](FHismMeshComponent& Component) {
			Component.Materials[Index] = Cast<UMaterialInterface>(AssetData.GetAsset());
		});
	}
	
	TSharedRef<SWidget> FHismMeshComponentInspector::CreateMeshPropertyWidget() {
		return SNew(SObjectPropertyEntryBox)
		.AllowedClass(UStaticMesh::StaticClass())
		.ObjectPath_Lambda([this]() {
			if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return FString(TEXT("Not Playing")); }
			if (!HismMeshComponent) { return FString(TEXT("No Hism Mesh Component")); }
			if (!HismMeshComponent->Mesh) { return FString(TEXT("No Mesh")); }
			return FAssetData(HismMeshComponent->Mesh).GetExportTextName();
		})
		.OnObjectChanged_Lambda([this](const FAssetData& AssetData) {
			if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return; }
			OnMeshChanged(AssetData);
		});
	}
	
	TSharedRef<SWidget> FHismMeshComponentInspector::CreateMaterialsWidget() {
		TSharedRef<SVerticalBox> MaterialsBox = SNew(SVerticalBox);

		for (int32 Index = 0; Index < HismMeshComponent->Materials.Num(); ++Index) {
			MaterialsBox->AddSlot()
			.AutoHeight()
			[
				SNew(SObjectPropertyEntryBox)
				.AllowedClass(UMaterialInterface::StaticClass())
				.ObjectPath_Lambda([this, Index]() {
					if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return FString(TEXT("Not Playing")); }
					if (!HismMeshComponent) { return FString(TEXT("No Skinned Mesh Component")); }
					if (Index >= HismMeshComponent->Materials.Num()) { return FString(TEXT("Invalid Index")); }
					if (!HismMeshComponent->Materials[Index]) { return FString(TEXT("No Material"));}
					return FAssetData(HismMeshComponent->Materials[Index]).GetExportTextName();
				})
				.OnObjectChanged_Lambda([this](const FAssetData& AssetData) {
					if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return; }
					OnMaterialChanged(0, AssetData); 
				})
			];
		}

		return MaterialsBox;
	}
}
