#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../Tags.h"

#include "Generated_UMoveToTargetCompleteTagBlueprintLibrary.generated.h"


UCLASS(BlueprintType)
class UMoveToTargetCompleteTagBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|MoveToTargetCompleteTag", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_MoveToTargetCompleteTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|MoveToTargetCompleteTag", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_MoveToTargetCompleteTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Tags|MoveToTargetCompleteTag", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_MoveToTargetCompleteTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|MoveToTargetCompleteTag", meta = (WorldContext = "WorldContextObject"))
    static void Remove_MoveToTargetCompleteTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|MoveToTargetCompleteTag", meta = (WorldContext = "WorldContextObject"))
    static void Erase_MoveToTargetCompleteTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Components|MoveToTargetCompleteTag", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_MoveToTargetCompleteTag(UObject* WorldContextObject);
};
