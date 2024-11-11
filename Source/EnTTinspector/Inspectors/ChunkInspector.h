#pragma once

#include "EnTTinspector/Include.h"

#include "EnTTue/Components/TransformComponents.h"

namespace Inspectors::TransformComponents {
	class FChunkComponentInspector : public IComponentInspector {
	public:
		FChunkComponent* ChunkComponent = nullptr;

		TArray<FName> ChunkEntitiesInVicinity;
		TArray<FName> NeighbouringEntitiesInVicinity;

		EEntity SelectedEntity = entt::null;

		FChunkComponentInspector(FEntityWorld& World, const EEntity Entity) : IComponentInspector(World, Entity) {}
		virtual TSharedPtr<SBorder> CreateWidget() override;
		virtual void Tick(UWorld* WorldRoot, FEntityWorld& EntityWorld, const float DeltaTime) override;
	};
}
