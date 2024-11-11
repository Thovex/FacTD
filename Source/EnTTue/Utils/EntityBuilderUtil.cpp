#include "EnTTue/Utils/EntityBuilderUtil.h"
#include "EnTTue/Components/CollisionComponents.h"
#include "EnTTue/Components/RenderingComponents.h"
#include "EnTTue/Components/Tags.h"
#include "EnTTue/Components/TransformComponents.h"
#include "EnTTue/UnrealFrameworks/VFX/EnTTueNiagara.h"
#include "EnTTue/Utils/EntityUtil.h"

#include "NiagaraComponent.h"

EEntity EntityBuilderUtil::CreateEntity(FEntityWorld& World, const FName& Name, EEntity Parent, const FTransform& Transform) {
	const EEntity Entity = CreateEntity(World, Name, Transform);

	World.Emplace<FParentComponent>(Entity, FParentComponent { .Parent = Parent });

	auto& [Children] = World.GetOrEmplace<FChildrenComponent>(Parent);
	Children.Add(Entity);
	
	return Entity;
}

EEntity EntityBuilderUtil::CreateEntity(FEntityWorld& World, const FName& Name, const FTransform& Transform) {
	const EEntity Entity = World.Create();

	World.Emplace<FNameComponent>(Entity, FNameComponent{.Name = Name});

	const FPositionComponent& WorldPositionComponent = World.Emplace<FPositionComponent>(Entity, Transform.GetLocation());
	World.Emplace<FLastPositionComponent>(Entity, WorldPositionComponent);

	const FRotationComponent& WorldRotationComponent = World.Emplace<FRotationComponent>(Entity, Transform.GetRotation().Rotator());
	World.Emplace<FLastRotationComponent>(Entity, WorldRotationComponent);

	const FScaleComponent& WorldScaleComponent = World.Emplace<FScaleComponent>(Entity, Transform.GetScale3D());
	World.Emplace<FLastScaleComponent>(Entity, WorldScaleComponent);

	return Entity;
}

EEntity EntityBuilderUtil::CreateSkinnedEntity(FEntityWorld& World, const FName& Name, const FTransform& Transform, USkeletalMesh* Mesh, const TSubclassOf<UEnTTueAnimationInstance> Anim) {
	const EEntity Entity = CreateEntity(World, Name, Transform);
	const EEntity SkinnedEntity = CreateEntity(World, FName(TEXT("Skinned-Entity")), Entity, FTransform::Identity);
	
	World.Emplace<FSkMeshComponent>(SkinnedEntity, FSkMeshComponent {
		.AnimInstance = Anim,
		.Mesh = Mesh,
	});

	World.Emplace<FTransformDirtyTag>(Entity);
	return Entity;
}

EEntity EntityBuilderUtil::CreateHismEntity(FEntityWorld& World, const FName& Name, const FTransform& Transform, UStaticMesh* Mesh, const TArray<UMaterialInterface*>& Materials) {
	const EEntity Entity = CreateEntity(World, Name, Transform);
	const EEntity HismEntity = CreateEntity(World, FName(TEXT("HISM-Entity")), Entity, FTransform::Identity);
	
	World.Emplace<FHismMeshComponent>(HismEntity, FHismMeshComponent{
		.Mesh = Mesh,
		.Materials = Materials,
	});

	World.Emplace<FTransformDirtyTag>(Entity);
	return Entity;
}

EEntity EntityBuilderUtil::CreateProjectile(FEntityWorld& World, const FTransform& Transform, UStaticMesh* Mesh, UMaterialInterface* Material) {
	const EEntity ProjectileEntity = CreateHismEntity(World, FName(TEXT("Projectile")), Transform, Mesh, { Material });

	World.Emplace<FVelocityComponent>(ProjectileEntity);
	World.Emplace<FAngularVelocityComponent>(ProjectileEntity);

	return ProjectileEntity;
}

EEntity EntityBuilderUtil::CreateParticle(const UObject* WorldContextObject, TSubclassOf<AEnTTueNiagara> NiagaraClass, FEntityWorld& World, const FTransform& Transform) {
	UWorld* UnrealWorld = WorldContextObject->GetWorld();
	if (!UnrealWorld) {
		return entt::null;
	}

	FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
	SpawnParameters.bNoFail = true;

	AEnTTueNiagara* EcsNiagara = UnrealWorld->SpawnActor<AEnTTueNiagara>(NiagaraClass, Transform, SpawnParameters);
	EcsNiagara->NiagaraComponent->Activate();

	const EEntity ParticleEntity = CreateEntity(World, "Particle", Transform);

	World.Emplace<FNiagaraComponent>(ParticleEntity, FNiagaraComponent {.NiagaraActor = EcsNiagara});

	return ParticleEntity;
}

