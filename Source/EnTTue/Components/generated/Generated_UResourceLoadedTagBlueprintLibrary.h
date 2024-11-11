#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../Tags.h"

#include "Generated_UResourceLoadedTagBlueprintLibrary.generated.h"


UCLASS(BlueprintType)
class UResourceLoadedTagBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|ResourceLoadedTag", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_ResourceLoadedTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|ResourceLoadedTag", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_ResourceLoadedTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Tags|ResourceLoadedTag", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_ResourceLoadedTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|ResourceLoadedTag", meta = (WorldContext = "WorldContextObject"))
    static void Remove_ResourceLoadedTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|ResourceLoadedTag", meta = (WorldContext = "WorldContextObject"))
    static void Erase_ResourceLoadedTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Components|ResourceLoadedTag", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_ResourceLoadedTag(UObject* WorldContextObject);
};
