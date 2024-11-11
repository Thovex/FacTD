#pragma once

#include "EnTTue/Include.h"

#include "WeaponUtil.generated.h"

UCLASS(BlueprintType)
class ENTTUE_API UWeaponLibrary : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static void CreateArtificialEnemyCollision(const UObject* WorldContextObject, int32 EntityId);
};

namespace WeaponUtil {
}

