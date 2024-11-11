#pragma once

#include "EnTTinspector/Include.h"

namespace Inspectors::CollisionComponents {
	static TArray<FName> CollisionProfileNames = { "Player", "Enemy" };

	class FBoxCollisionComponentInspector : public IComponentInspector {
	public:
		FBoxCollisionComponent* BoxCollisionComponent = nullptr;

		bool bVisualizeCollision = false;

		FBoxCollisionComponentInspector(FEntityWorld& World, const EEntity Entity) : IComponentInspector(World, Entity) {}
		virtual TSharedPtr<SBorder> CreateWidget() override;
		virtual void Tick(UWorld* WorldRoot, FEntityWorld& EntityWorld, const float DeltaTime) override;
	protected:
		UBoxComponent* GetBox();
	};
}
