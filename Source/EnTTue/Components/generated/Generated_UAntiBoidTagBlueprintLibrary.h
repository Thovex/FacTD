#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../TransformComponents.h"

#include "Generated_UAntiBoidTagBlueprintLibrary.generated.h"


UCLASS(BlueprintType)
class UAntiBoidTagBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|AntiBoidTag", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_AntiBoidTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|AntiBoidTag", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_AntiBoidTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Tags|AntiBoidTag", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_AntiBoidTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|AntiBoidTag", meta = (WorldContext = "WorldContextObject"))
    static void Remove_AntiBoidTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|AntiBoidTag", meta = (WorldContext = "WorldContextObject"))
    static void Erase_AntiBoidTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Components|AntiBoidTag", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_AntiBoidTag(UObject* WorldContextObject);
};
