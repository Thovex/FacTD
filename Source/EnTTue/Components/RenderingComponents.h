#pragma once

#include "EnTTue/UnrealFrameworks/Animation/EnTTueAnimationInstance.h"

#include "RenderingComponents.generated.h"

class AEnTTueNiagara;
class UMaterialInstanceDynamic;
class USkeletalMesh;
class UHierarchicalInstancedStaticMeshComponent;
class UMaterialInterface;
class UStaticMesh;

USTRUCT(Blueprintable)
struct FHismMeshComponent // APPLY_ENTTUE_REFLECTION()
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UStaticMesh* Mesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<UMaterialInterface*> Materials;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TEnumAsByte<ECollisionChannel> CollisionChannel = ECollisionChannel::ECC_Visibility;
	
	UPROPERTY() UHierarchicalInstancedStaticMeshComponent* UnrealHism = nullptr;
	UPROPERTY() int32 InstanceId = -1;
	UPROPERTY() UStaticMesh* InstancePtr = nullptr;
};

USTRUCT(Blueprintable)
struct FSkMeshComponent // APPLY_ENTTUE_REFLECTION()
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<UEnTTueAnimationInstance> AnimInstance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USkeletalMesh* Mesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<UMaterialInterface*> Materials; 

	// At Runtime
	UPROPERTY() USkeletalMeshComponent* UnrealSkm = nullptr;
	UPROPERTY() UEnTTueAnimationInstance* AnimInst = nullptr;
	UPROPERTY() TArray<UMaterialInstanceDynamic*> MaterialInstances;
};

struct FNiagaraComponent {
	AEnTTueNiagara* NiagaraActor = nullptr;
};

struct FFresnelFlashComponent {
	bool Start = true;
	float Value = 0.f;
	float Speed = 5.f;
	
	static float EaseInQuint(const float X) {
		return X * X * X * X * X;
	}
};
