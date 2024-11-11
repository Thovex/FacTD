#pragma once

#include "EnTTue/Include.h"

#include "TransformUtil.generated.h"

UCLASS(BlueprintType)
class ENTTUE_API UTransformLibrary : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

	/* Name Component */
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static void Set_NameComponent(const UObject* WorldContextObject, const int32 EntityId, const FNameComponent& NameComponent);

	/* Position Component */
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static void Set_PositionComponent(const UObject* WorldContextObject, const int32 EntityId, const FPositionComponent& PositionComponent);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static void Get_PositionComponent(const UObject* WorldContextObject, const int32 EntityId, FPositionComponent& PositionComponent);

	/* Rotation Component */
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static void Get_RotationComponent(const UObject* WorldContextObject, const int32 EntityId, FRotationComponent& RotationComponent);

	/* Velocity Component */
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static void Set_VelocityComponent(const UObject* WorldContextObject, const int32 EntityId, const FVelocityComponent& VelocityComponent);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static void Get_VelocityComponent(const UObject* WorldContextObject, const int32 EntityId, FVelocityComponent& VelocityComponent);
	
};

namespace TransformUtil {
	ENTTUE_API FTransform GetTransform(FRegistry& Reg, EEntity Entity);
	ENTTUE_API void HandleKnockBack(FRegistry& Reg, const EEntity KnockBackEntity, const float KnockBackTimer, const float KnockBackPower, const FVector& KnockBackDirection, const bool Force);
}
