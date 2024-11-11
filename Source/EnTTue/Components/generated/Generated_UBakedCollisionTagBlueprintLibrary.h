#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../Tags.h"

#include "Generated_UBakedCollisionTagBlueprintLibrary.generated.h"


UCLASS(BlueprintType)
class UBakedCollisionTagBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|BakedCollisionTag", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_BakedCollisionTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|BakedCollisionTag", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_BakedCollisionTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Tags|BakedCollisionTag", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_BakedCollisionTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|BakedCollisionTag", meta = (WorldContext = "WorldContextObject"))
    static void Remove_BakedCollisionTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|BakedCollisionTag", meta = (WorldContext = "WorldContextObject"))
    static void Erase_BakedCollisionTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Components|BakedCollisionTag", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_BakedCollisionTag(UObject* WorldContextObject);
};
