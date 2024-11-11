#pragma once

#include "EnTTue/Include.h"

#include "CommonUtil.generated.h"

UCLASS(BlueprintType)
class ENTTUE_API UCommonLibrary : public UBlueprintFunctionLibrary {
	GENERATED_BODY()
};

namespace CommonUtil {
	ENTTUE_API FName ComponentTypeInfoToName(const entt::type_info& Info);
}
