#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../Tags.h"

#include "Generated_UDrawDebugTagBlueprintLibrary.generated.h"


UCLASS(BlueprintType)
class UDrawDebugTagBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|DrawDebugTag", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_DrawDebugTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|DrawDebugTag", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_DrawDebugTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Tags|DrawDebugTag", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_DrawDebugTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|DrawDebugTag", meta = (WorldContext = "WorldContextObject"))
    static void Remove_DrawDebugTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|DrawDebugTag", meta = (WorldContext = "WorldContextObject"))
    static void Erase_DrawDebugTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Components|DrawDebugTag", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_DrawDebugTag(UObject* WorldContextObject);
};
