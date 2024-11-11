#pragma once

#include "EnTTinspector/Include.h"

namespace Inspectors::RenderingComponents {
	class FSkinnedMeshComponentInspector : public IComponentInspector {
	public:
		FSkMeshComponent* SkinnedMeshComponent = nullptr;

		FSkinnedMeshComponentInspector(FEntityWorld& World, const EEntity Entity) : IComponentInspector(World, Entity) {}
		virtual TSharedPtr<SBorder> CreateWidget() override;

	private:
		void OnMeshChanged(const FAssetData& AssetData);
		void OnMaterialChanged(int32 Index, const FAssetData& AssetData);
		
		TSharedRef<SWidget> CreateMeshPropertyWidget();
		TSharedRef<SWidget> CreateMaterialsWidget();
	};

	class FHismMeshComponentInspector : public IComponentInspector {
	public:
		FHismMeshComponent* HismMeshComponent = nullptr;

		FHismMeshComponentInspector(FEntityWorld& World, const EEntity Entity) : IComponentInspector(World, Entity) {}
		virtual TSharedPtr<SBorder> CreateWidget() override;

	private:
		void OnMeshChanged(const FAssetData& AssetData);
		void OnMaterialChanged(int32 Index, const FAssetData& AssetData);

		TSharedRef<SWidget> CreateMeshPropertyWidget();
		TSharedRef<SWidget> CreateMaterialsWidget();
	};
}
