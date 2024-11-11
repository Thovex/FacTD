#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../FacTD_GridComponents.h"

#include "Generated_UFacTD_DirectionDirtyTagBlueprintLibrary.generated.h"


UCLASS(BlueprintType)
class UFacTD_DirectionDirtyTagBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|FacTD_DirectionDirtyTag", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_FacTD_DirectionDirtyTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|FacTD_DirectionDirtyTag", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_FacTD_DirectionDirtyTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Tags|FacTD_DirectionDirtyTag", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_FacTD_DirectionDirtyTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|FacTD_DirectionDirtyTag", meta = (WorldContext = "WorldContextObject"))
    static void Remove_FacTD_DirectionDirtyTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|FacTD_DirectionDirtyTag", meta = (WorldContext = "WorldContextObject"))
    static void Erase_FacTD_DirectionDirtyTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Components|FacTD_DirectionDirtyTag", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_FacTD_DirectionDirtyTag(UObject* WorldContextObject);
};
