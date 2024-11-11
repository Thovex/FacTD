#pragma once

#include "EnTTue/Include.h"

#include "EntityBuilderUtil.generated.h"

class UMaterialInstanceDynamic;
class USkeletalMesh;
class UHierarchicalInstancedStaticMeshComponent;
class UMaterialInterface;
class UStaticMesh;

UCLASS(BlueprintType)
class ENTTUE_API UEntityBuilderLibrary : public UBlueprintFunctionLibrary {
	GENERATED_BODY()
};

namespace EntityBuilderUtil {
	ENTTUE_API EEntity CreateEntity(FEntityWorld& World, const FName& Name, EEntity Parent, const FTransform& Transform);
	ENTTUE_API EEntity CreateEntity(FEntityWorld& World, const FName& Name, const FTransform& Transform);
	ENTTUE_API EEntity CreateSkinnedEntity(FEntityWorld& World, const FName& Name, const FTransform& Transform, USkeletalMesh* Mesh, const TSubclassOf<UEnTTueAnimationInstance> Anim);
	ENTTUE_API EEntity CreateHismEntity(FEntityWorld& World, const FName& Name, const FTransform& Transform, UStaticMesh* Mesh, const TArray<UMaterialInterface*>& Materials);
	ENTTUE_API EEntity CreateProjectile(FEntityWorld& World, const FTransform& Transform, UStaticMesh* Mesh, UMaterialInterface* Material);
	ENTTUE_API EEntity CreateParticle(const UObject* WorldContextObject, TSubclassOf<AEnTTueNiagara> NiagaraClass, FEntityWorld& World, const FTransform& Transform);
}
