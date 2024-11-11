#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../Tags.h"

#include "Generated_ULookAtVelocityTagBlueprintLibrary.generated.h"


UCLASS(BlueprintType)
class ULookAtVelocityTagBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|LookAtVelocityTag", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_LookAtVelocityTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|LookAtVelocityTag", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_LookAtVelocityTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Tags|LookAtVelocityTag", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_LookAtVelocityTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|LookAtVelocityTag", meta = (WorldContext = "WorldContextObject"))
    static void Remove_LookAtVelocityTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|LookAtVelocityTag", meta = (WorldContext = "WorldContextObject"))
    static void Erase_LookAtVelocityTag(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Components|LookAtVelocityTag", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_LookAtVelocityTag(UObject* WorldContextObject);
};
