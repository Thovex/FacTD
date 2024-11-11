#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../Tags.h"

#include "Generated_UTransformDirtyTagBlueprintLibrary.generated.h"


UCLASS(BlueprintType)
class UTransformDirtyTagBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|TransformDirtyTag", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_TransformDirtyTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|TransformDirtyTag", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_TransformDirtyTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Tags|TransformDirtyTag", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_TransformDirtyTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|TransformDirtyTag", meta = (WorldContext = "WorldContextObject"))
    static void Remove_TransformDirtyTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|TransformDirtyTag", meta = (WorldContext = "WorldContextObject"))
    static void Erase_TransformDirtyTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Components|TransformDirtyTag", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_TransformDirtyTag(UObject* WorldContextObject);
};
