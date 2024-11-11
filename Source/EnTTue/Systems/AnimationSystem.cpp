#include "EnTTue/Systems/AnimationSystem.h"

#include <EnTTue/Utils/EntityUtil.h>

#include "EnTTue/Components/RenderingComponents.h"
#include "EnTTue/Components/Tags.h"
#include "EnTTue/Components/TransformComponents.h"
#include "EnTTue/UnrealFrameworks/Animation/EnTTueAnimationInstance.h"

void UAnimationSystem::Tick(AActor* ActorRoot, FEntityWorld& World, const float DeltaTime) {
	FRegistry& Reg = World.Registry;

	for (auto&& [Entity, SkinnedMeshComponent] : World.ForEach<FSkMeshComponent, FResourceLoadedTag, FBakedAnimationsTag>()) {
		{
			const EEntity VelocityEntity = EntityUtil::FindParentWithComponent<FVelocityComponent>(World, Entity, true);
			if (World.Valid(VelocityEntity))
			{
				const auto& Velocity = World.Get<FVelocityComponent>(VelocityEntity);
				
				SkinnedMeshComponent.AnimInst->Velocity = Velocity.Delta;
				const float SqrMag = SkinnedMeshComponent.AnimInst->Velocity.SizeSquared2D();
				SkinnedMeshComponent.AnimInst->ShouldMove = !FMath::IsNearlyEqual(SqrMag, 0, 0.1f);
			}

		}
		
		{	// Handle ShouldAttack on Animation Blueprints
			const EEntity MoveTargetParent = EntityUtil::FindParentWithComponent<FMoveToTargetComponent>(World, Entity, true);
			if (World.Valid(MoveTargetParent))
			{
				const auto& MoveToTarget = World.Get<FMoveToTargetComponent>(MoveTargetParent);
				if (World.Valid(MoveToTarget.Target) && MoveToTarget.Distance != -1.f)
				{
					SkinnedMeshComponent.AnimInst->ShouldAttack = MoveToTarget.Distance <= MoveToTarget.DistanceTillStop;
				}
			}
		}
	}
	
}
