#include "EnTTue/Systems/CleanupSystem.h"
#include "EnTTue/Components/CollisionComponents.h"
#include "EnTTue/Components/EnTTueEvents.h"
#include "EnTTue/Components/RenderingComponents.h"
#include "EnTTue/Components/Tags.h"
#include "EnTTue/Components/TransformComponents.h"
#include "EnTTue/UnrealFrameworks/Collision/EnTTueCollision.h"
#include "EnTTue/UnrealFrameworks/VFX/EnTTueNiagara.h"
#include "EnTTue/Utils/EntityUtil.h"

#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"

void UCleanupSystem::Tick(AActor* ActorRoot, FEntityWorld& World, const float DeltaTime) {
	FRegistry& Reg = World.Registry;

	// Updates should have been done at this point.
	for (auto&& [Entity] : World.ForEach<FTransformDirtyTag>()) {
		World.Erase<FTransformDirtyTag>(Entity);
	}

	Reg.view<FCollisionComponent>().each([&](const EEntity Entity, FCollisionComponent& CollisionComponent) {
		if (!CollisionComponent.Destroy) {
			CollisionComponent.Destroy = true;
			return;
		}

		if (!Reg.valid(CollisionComponent.ColliderEntity) || !Reg.valid(CollisionComponent.OtherEntity)) {
			World.Emplace<FDestroyAtEndOfTickTag>(Entity);
			return;
		}

		// If we're supposed to be a one time collision, we destroy.
		const FBoxCollisionComponent* BoxCollision = Reg.try_get<FBoxCollisionComponent>(CollisionComponent.ColliderEntity);
		if (BoxCollision && BoxCollision->DestroyOnCollision) {
			World.EmplaceOrReplace<FDestroyAtEndOfTickTag>(CollisionComponent.ColliderEntity);
		}

		const FSphereCollisionComponent* SphereCollision = Reg.try_get<FSphereCollisionComponent>(CollisionComponent.ColliderEntity);
		if (SphereCollision && SphereCollision->DestroyOnCollision) {
			World.EmplaceOrReplace<FDestroyAtEndOfTickTag>(CollisionComponent.ColliderEntity);
		}

		World.EmplaceOrReplace<FDestroyAtEndOfTickTag>(Entity);
		World.Remove<FCollisionComponent>(Entity);
	});
	
	Reg.view<FWasRecentlyKnockedBackTag>().each([&](const EEntity Entity, FWasRecentlyKnockedBackTag& RecentKnockBack) {
		RecentKnockBack.GraceTimer -= DeltaTime;

		if (RecentKnockBack.GraceTimer <= 0.f) {
			World.Remove<FWasRecentlyKnockedBackTag>(Entity);
		}
	});
	
	for (auto&& [Entity] : World.ForEach<FDestroyAtEndOfTickTag>())
	{
		EntityUtil::ForEachRelative(World, Entity, true, [&](const EEntity RelativeEntity) {
			World.EmplaceOrReplace<FDestroyAtEndOfTickTag>(RelativeEntity);
		}); 
	}

	Reg.view<FDestroyAtEndOfTickTag>().each([&](const EEntity Entity) {
		// Unsubscribe Collision Boxes
		const FBoxCollisionComponent* BoxCollisionComponent = World.TryGet<FBoxCollisionComponent>(Entity);
		if (BoxCollisionComponent) {
			if (BoxCollisionComponent->CollisionActor) {
				BoxCollisionComponent->CollisionActor->Destroy();
			}
		}

		// Unsubscribe Collision Boxes
		const FSphereCollisionComponent* SphereCollisionComponent = World.TryGet<FSphereCollisionComponent>(Entity);
		if (SphereCollisionComponent) {
			if (SphereCollisionComponent->CollisionActor) {
				SphereCollisionComponent->CollisionActor->Destroy();
			}
		}
		
		if (World.AllOf<FFresnelFlashComponent>(Entity)) {
			// Wait for FresnelFlash End!
			//UE_LOG(LogECS, Display, TEXT("Awaiting Fresnel Completion"));
			return;
		}

		const FNiagaraComponent* NiagaraComponent = World.TryGet<FNiagaraComponent>(Entity);
		if (NiagaraComponent && NiagaraComponent->NiagaraActor){
			NiagaraComponent->NiagaraActor->Destroy();
		}
		
		const FSkMeshComponent* SkinnedMeshComponent = World.TryGet<FSkMeshComponent>(Entity);
		if (SkinnedMeshComponent && SkinnedMeshComponent->UnrealSkm) {
			SkinnedMeshComponent->UnrealSkm->DestroyComponent();
			World.Remove<FSkMeshComponent>(Entity);
		}

		// Unsubscribe Mesh Types
		const FHismMeshComponent* HismMeshComponent = World.TryGet<FHismMeshComponent>(Entity);
		if (HismMeshComponent && HismMeshComponent->InstanceId != -1 && HismMeshComponent->UnrealHism) {
			int32 RemovedInstanceId = HismMeshComponent->InstanceId;
			if (HismMeshComponent->UnrealHism->RemoveInstance(RemovedInstanceId)) {
				// Update all instances with higher IDs
				Reg.view<FHismMeshComponent>().each([&](const EEntity OtherEntity, FHismMeshComponent& OtherHismMeshComponent) {
					if (Entity == OtherEntity) {
						return;
					}

					if (HismMeshComponent->Mesh != OtherHismMeshComponent.Mesh) {
						return;
					}

					if (OtherHismMeshComponent.InstanceId > RemovedInstanceId) {
						OtherHismMeshComponent.InstanceId--;
						World.EmplaceOrReplace<FTransformDirtyTag>(OtherEntity);
					}
				});

				World.Remove<FHismMeshComponent>(Entity);
			}
		}


		// TODO: Skinned Meshes.. When enemies come :)

		UE_LOG(LogTemp, Warning, TEXT("Destroying Entity %d"), EntityUtil::ToUint32(Entity));
		Reg.destroy(Entity);
	});
	
}
