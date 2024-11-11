#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../Tags.h"

#include "Generated_UBakedAnimationsTagBlueprintLibrary.generated.h"


UCLASS(BlueprintType)
class UBakedAnimationsTagBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|BakedAnimationsTag", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_BakedAnimationsTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|BakedAnimationsTag", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_BakedAnimationsTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Tags|BakedAnimationsTag", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_BakedAnimationsTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|BakedAnimationsTag", meta = (WorldContext = "WorldContextObject"))
    static void Remove_BakedAnimationsTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|BakedAnimationsTag", meta = (WorldContext = "WorldContextObject"))
    static void Erase_BakedAnimationsTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Components|BakedAnimationsTag", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_BakedAnimationsTag(UObject* WorldContextObject);
};
