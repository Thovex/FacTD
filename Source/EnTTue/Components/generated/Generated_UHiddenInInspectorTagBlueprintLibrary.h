#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../Tags.h"

#include "Generated_UHiddenInInspectorTagBlueprintLibrary.generated.h"


UCLASS(BlueprintType)
class UHiddenInInspectorTagBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|HiddenInInspectorTag", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_HiddenInInspectorTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|HiddenInInspectorTag", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_HiddenInInspectorTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Tags|HiddenInInspectorTag", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_HiddenInInspectorTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|HiddenInInspectorTag", meta = (WorldContext = "WorldContextObject"))
    static void Remove_HiddenInInspectorTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|HiddenInInspectorTag", meta = (WorldContext = "WorldContextObject"))
    static void Erase_HiddenInInspectorTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Components|HiddenInInspectorTag", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_HiddenInInspectorTag(UObject* WorldContextObject);
};
