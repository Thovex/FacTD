#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../Tags.h"

#include "Generated_UDestroyAtEndOfTickTagBlueprintLibrary.generated.h"


UCLASS(BlueprintType)
class UDestroyAtEndOfTickTagBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|DestroyAtEndOfTickTag", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_DestroyAtEndOfTickTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|DestroyAtEndOfTickTag", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_DestroyAtEndOfTickTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Tags|DestroyAtEndOfTickTag", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_DestroyAtEndOfTickTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|DestroyAtEndOfTickTag", meta = (WorldContext = "WorldContextObject"))
    static void Remove_DestroyAtEndOfTickTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|DestroyAtEndOfTickTag", meta = (WorldContext = "WorldContextObject"))
    static void Erase_DestroyAtEndOfTickTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Components|DestroyAtEndOfTickTag", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_DestroyAtEndOfTickTag(UObject* WorldContextObject);
};
