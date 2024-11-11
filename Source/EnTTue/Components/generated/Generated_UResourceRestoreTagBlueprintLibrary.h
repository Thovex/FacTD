#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../Tags.h"

#include "Generated_UResourceRestoreTagBlueprintLibrary.generated.h"


UCLASS(BlueprintType)
class UResourceRestoreTagBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|ResourceRestoreTag", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_ResourceRestoreTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|ResourceRestoreTag", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_ResourceRestoreTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Tags|ResourceRestoreTag", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_ResourceRestoreTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|ResourceRestoreTag", meta = (WorldContext = "WorldContextObject"))
    static void Remove_ResourceRestoreTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|ResourceRestoreTag", meta = (WorldContext = "WorldContextObject"))
    static void Erase_ResourceRestoreTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Components|ResourceRestoreTag", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_ResourceRestoreTag(UObject* WorldContextObject);
};
