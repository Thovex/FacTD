// Fill out your copyright notice in the Description page of Project Settings.

#include "EnTTue/Systems/RenderingSystem.h"

#include "EnTTue/Components/RenderingComponents.h"
#include "EnTTue/Components/Tags.h"
#include "EnTTue/Components/TransformComponents.h"
#include "EnTTue/UnrealFrameworks/Animation/EnTTueAnimationInstance.h"
#include "EnTTue/UnrealFrameworks/VFX/EnTTueNiagara.h"
#include "EnTTue/Utils/EntityUtil.h"

#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"

#include "Engine/SkeletalMesh.h"
#include "Engine/SkinnedAssetCommon.h"

#include "Materials/MaterialInstanceDynamic.h"

void URenderingSystem::Tick(AActor* ActorRoot, FEntityWorld& World, const float DeltaTime) {
	for (auto&& [Entity, SkinnedMeshComponent] : World.ForEach<FSkMeshComponent>(entt::exclude<FResourceLoadedTag>)) {
		if (SkinnedMeshComponent.Mesh == nullptr) {
			return;
		}

		const int32 EntityId = static_cast<int32>(Entity);

		if (World.AllOf<FResourceRestoreTag>(Entity)) {
			SkeletalMeshComponents.Remove(EntityId);
			
			SkinnedMeshComponent.UnrealSkm->DestroyComponent();
			SkinnedMeshComponent.UnrealSkm = nullptr;

			SkinnedMeshComponent.MaterialInstances.Empty();
			
			SkinnedMeshComponent.AnimInst = nullptr;
			
			World.Erase<FResourceRestoreTag>(Entity);
		}

		if (!SkeletalMeshComponents.Contains(EntityId)) {
			USkeletalMeshComponent* SkeletalMeshComponent = NewObject<USkeletalMeshComponent>(ActorRoot);
			SkeletalMeshComponent->AttachToComponent(ActorRoot->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			SkeletalMeshComponent->RegisterComponent();
			SkeletalMeshComponent->SetWorldTransform(
				FTransform(World.GetWorldRotation(Entity), World.GetWorldPosition(Entity), World.GetWorldScale(Entity)),
				false, nullptr, ETeleportType::ResetPhysics);

			SkeletalMeshComponent->SetSkeletalMesh(SkinnedMeshComponent.Mesh);

			if (SkinnedMeshComponent.Materials.IsEmpty()) {
				// Write Default Materials to this Structure
				auto& DefaultSkeletalMeshMaterials = SkinnedMeshComponent.Mesh->GetMaterials();
				for (int32 i = 0; i < DefaultSkeletalMeshMaterials.Num(); i++) {
					SkinnedMeshComponent.Materials.Add(DefaultSkeletalMeshMaterials[i].MaterialInterface);
				}
			}

			int32 MatIndex = 0;
			for (UMaterialInterface* MaterialInterface : SkinnedMeshComponent.Materials) {
				UMaterialInstanceDynamic* Dynamic = UMaterialInstanceDynamic::Create(MaterialInterface, SkeletalMeshComponent);
				UE_LOG(LogECS, Display, TEXT("Created Dyn Material from %s to SkinnedMeshComponent"), *MaterialInterface->GetName());
				
				SkeletalMeshComponent->SetMaterial(MatIndex, Dynamic);
				SkinnedMeshComponent.MaterialInstances.Add(Dynamic);
				MatIndex++;
			}

			SkeletalMeshComponent->SetAnimInstanceClass(SkinnedMeshComponent.AnimInstance);
			SkeletalMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

			if (auto* AnimInst = SkeletalMeshComponent->GetAnimInstance()) {
				SkinnedMeshComponent.AnimInst = static_cast<UEnTTueAnimationInstance*>(AnimInst);
				SkinnedMeshComponent.AnimInst->OwnerEntityId = EntityId;
				SkinnedMeshComponent.AnimInst->OwnerEntity = Entity;
				World.Emplace<FBakedAnimationsTag>(Entity);
			}

			SkeletalMeshComponents.Add(EntityId, SkeletalMeshComponent);
		}

		// Set Pointer to UnrealSkm to unsubscribe to in a later stage.
		SkinnedMeshComponent.UnrealSkm = SkeletalMeshComponents[EntityId];
		
		World.Emplace<FResourceLoadedTag>(Entity);
	}

	// Purpose: Instantiation of a Hism Mesh Component.

	for (auto&& [Entity, HismMeshComponent] : World.ForEach<FHismMeshComponent>(entt::exclude<FResourceLoadedTag>)) {
		if (HismMeshComponent.Mesh == nullptr) {
			continue;
		}
		
		if (World.AllOf<FResourceRestoreTag>(Entity)) {
			HismMeshComponents[HismMeshComponent.InstancePtr]->RemoveInstance(HismMeshComponent.InstanceId);

			if (HismMeshComponents[HismMeshComponent.InstancePtr]->GetInstanceCount() == 0) {
				HismMeshComponents[HismMeshComponent.InstancePtr]->DestroyComponent();
				HismMeshComponents.Remove(HismMeshComponent.InstancePtr);
			}

			HismMeshComponent.InstancePtr = nullptr;
			
			World.Erase<FResourceRestoreTag>(Entity);
		}

		if (!HismMeshComponents.Contains(HismMeshComponent.Mesh)) {
			UHierarchicalInstancedStaticMeshComponent* HismComponent = NewObject<UHierarchicalInstancedStaticMeshComponent>(ActorRoot);
			HismComponent->AttachToComponent(ActorRoot->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			HismComponent->RegisterComponent();

			HismComponent->SetStaticMesh(HismMeshComponent.Mesh);
			HismComponent->SetCollisionObjectType(HismMeshComponent.CollisionChannel);

			int32 Index = 0;
			for (UMaterialInterface* MaterialInterface : HismMeshComponent.Materials) {
				HismComponent->SetMaterial(Index, MaterialInterface);
				Index++;
			}

			//HismComponent->SetCastShadow(false);

			// We have a new HismMeshComponent on our ActorRoot
			HismMeshComponents.Add(HismMeshComponent.Mesh, HismComponent);
		}


		// Set Pointer to UnrealHism to unsubscribe to in a later stage.
		HismMeshComponent.UnrealHism = HismMeshComponents[HismMeshComponent.Mesh];

		HismMeshComponent.InstanceId = HismMeshComponents[HismMeshComponent.Mesh]->AddInstance(
			FTransform(
				World.GetWorldRotation(Entity),
				World.GetWorldPosition(Entity),
				World.GetWorldScale(Entity)
			), true);
		
		HismMeshComponent.InstancePtr = HismMeshComponent.Mesh;

		//UE_LOG(LogECS, Display, TEXT("Added new Instance to HISM with Id: %d"), HismMeshComponent.InstanceId);

		World.Emplace<FResourceLoadedTag>(Entity);
	}

	// Purpose: Update Transforms of Dirty Skeletal Mesh Component;
	for (auto&& [Entity, SkinnedMeshComponent] : World.ForEach<FSkMeshComponent, FResourceLoadedTag, FTransformDirtyTag>(entt::exclude<FStaticTag>)) {
		SkeletalMeshComponents[EntityUtil::ToUint32(Entity)]->SetWorldTransform(FTransform(
			World.GetWorldRotation(Entity),
			World.GetWorldPosition(Entity),
			World.GetWorldScale(Entity)
		));
	}

	// Purpose: Update Transforms of Dirty Hism Mesh Component;
	for (auto&& [Entity, HismMeshComponent] : World.ForEach<FHismMeshComponent, FResourceLoadedTag, FTransformDirtyTag>(entt::exclude<FStaticTag>)) {
		HismMeshComponents[HismMeshComponent.Mesh]->UpdateInstanceTransform(HismMeshComponent.InstanceId,
			FTransform(
				World.GetWorldRotation(Entity),
				World.GetWorldPosition(Entity),
				World.GetWorldScale(Entity)
		), true);
	}

	for (auto&& [Entity, NiagaraComponent] : World.ForEach<FNiagaraComponent, FTransformDirtyTag, FResourceLoadedTag>(entt::exclude<FStaticTag>)) {
		NiagaraComponent.NiagaraActor->SetActorTransform(
			FTransform(
				World.GetWorldRotation(Entity),
				World.GetWorldPosition(Entity),
				World.GetWorldScale(Entity))
		);
	}

	for (auto&& [Entity, SkinnedMeshComponent, FresnelFlash] : World.ForEach<FSkMeshComponent, FFresnelFlashComponent>()) {
		//FresnelFlash.EaseInQuint(FresnelFlash.Value);

		if (FresnelFlash.Start) {
			FresnelFlash.Value += DeltaTime * FresnelFlash.Speed;
			//UE_LOG(LogECS, Display, TEXT("FresnelValue: %f"), FresnelFlash.Value);
		} else {
			FresnelFlash.Value -= DeltaTime * FresnelFlash.Speed;
			//UE_LOG(LogECS, Display, TEXT("FresnelValue: %f"), FresnelFlash.Value);
		}

		if (FresnelFlash.Value >= 1.f) {
			FresnelFlash.Value = 1.f;
			FresnelFlash.Start = false;
			//UE_LOG(LogECS, Display, TEXT("Fresnel TURN"));
		}

		for (UMaterialInstanceDynamic* Material : SkinnedMeshComponent.MaterialInstances) {
			Material->SetScalarParameterValue(FName(TEXT("Fresnel")), FresnelFlash.EaseInQuint(FresnelFlash.Value));
		}

		if (!FresnelFlash.Start && FresnelFlash.Value <= 0.f) {
			World.Erase<FFresnelFlashComponent>(Entity);
		}
	}
}
