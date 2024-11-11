#include "EnTTue/Systems/CollisionSystem.h"
#include "EnTTue/Components/Tags.h"
#include "EnTTue/Components/TransformComponents.h"
#include "EnTTue/UnrealFrameworks/Collision/EnTTueBoxCollision.h"
#include "EnTTue/UnrealFrameworks/Collision/EnTTueCollision.h"
#include "EnTTue/UnrealFrameworks/Collision/EnTTueSphereCollision.h"
#include "EnTTue/Components/CollisionComponents.h"

#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"

#include "Engine/World.h"

void UCollisionSystem::SetupCollisions(const AActor* ActorRoot, FEntityWorld& World, FRegistry& Reg) const {

	for (auto&& [Entity, BoxCollisionComp] : World.ForEach<FBoxCollisionComponent, FResourceRestoreTag>()) {
		World.Erase<FResourceRestoreTag>(Entity);
		
		if (!IsValid(BoxCollisionComp.CollisionActor)) { 
			continue;
		}

		BoxCollisionComp.CollisionActor->Destroy();
		BoxCollisionComp.CollisionActor = nullptr;
	}

	for (auto&& [Entity, BoxCollisionComp, PositionComp] : World.ForEach<FBoxCollisionComponent, FPositionComponent>(entt::exclude<FBakedCollisionTag>)) {
		UWorld* UnrealWorld = ActorRoot->GetWorld();

		const FTransform Transform(FQuat::Identity, PositionComp + BoxCollisionComp.Offset, FVector::OneVector);
		
		AEnTTueBoxCollision* CollisionActor = UnrealWorld->SpawnActorDeferred<AEnTTueBoxCollision>(UCollisionSystem::BoxCollision, Transform,
		nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
		
		CollisionActor->BoxCollision->SetCollisionProfileName(BoxCollisionComp.CollisionProfile);
		CollisionActor->World = &World;
		CollisionActor->CollisionOwner = Entity;
		CollisionActor->CallbackEntity = BoxCollisionComp.CallbackEntity;
	
		BoxCollisionComp.CollisionActor = CollisionActor;
	
		UGameplayStatics::FinishSpawningActor(CollisionActor, Transform);

		CollisionActor->BoxCollision->SetBoxExtent(BoxCollisionComp.Extents, true);
		CollisionActor->BoxCollision->SetSimulatePhysics(true);
		CollisionActor->BoxCollision->SetEnableGravity(false);

		Reg.emplace<FBakedCollisionTag>(Entity);
	}

	Reg.view<FSphereCollisionComponent, FPositionComponent>(entt::exclude<FBakedCollisionTag>).
	each([&](const EEntity Entity, FSphereCollisionComponent& SphereCollision, const FPositionComponent& Position) {
		UWorld* UnrealWorld = ActorRoot->GetWorld();

		const FTransform Transform(FQuat::Identity, Position + SphereCollision.Offset, FVector::OneVector);

		AEnTTueSphereCollision* CollisionActor = UnrealWorld->SpawnActorDeferred<AEnTTueSphereCollision>(UCollisionSystem::SphereCollision, Transform,
		nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
				
		CollisionActor->SphereCollision->SetCollisionProfileName(SphereCollision.CollisionProfile);
		CollisionActor->World = &World;
		CollisionActor->CollisionOwner = Entity;
		CollisionActor->CallbackEntity = SphereCollision.CallbackEntity;
			
		SphereCollision.CollisionActor = CollisionActor;
			
		UGameplayStatics::FinishSpawningActor(CollisionActor, Transform);

		CollisionActor->SphereCollision->SetSphereRadius(SphereCollision.Radius, true);

		Reg.emplace<FBakedCollisionTag>(Entity);
	});

}

template<typename T>
void UpdateActorLocation(FEntityWorld& World, const EEntity& Entity, const T& CollisionComponent) {
	if (!IsValid(CollisionComponent.CollisionActor)) { 
		return;
	}
	
	CollisionComponent.CollisionActor->SetActorLocation(World.GetWorldPosition(Entity) + CollisionComponent.Offset);
}

void UpdateCollisions(FEntityWorld& World) {
	for (auto&& [Entity, BoxCollision] : World.ForEach<FBoxCollisionComponent, FBakedCollisionTag, FTransformDirtyTag>()) {
		UpdateActorLocation<FBoxCollisionComponent>(World, Entity, BoxCollision);
	}
	
	for (auto&& [Entity, SphereCollision] : World.ForEach<FSphereCollisionComponent, FBakedCollisionTag, FTransformDirtyTag>()) {
		UpdateActorLocation<FSphereCollisionComponent>(World, Entity, SphereCollision);
	}
}

void UCollisionSystem::Tick(AActor* ActorRoot, FEntityWorld& World, const float DeltaTime) {
	FRegistry& Reg = World.Registry;

	SetupCollisions(ActorRoot, World, Reg);
	UpdateCollisions(World);
}
