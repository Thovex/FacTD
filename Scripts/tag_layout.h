#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

$IncludePath$

#include "Generated_U$TypeName$BlueprintLibrary.generated.h"


UCLASS(BlueprintType)
class U$TypeName$BlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_$TypeName$(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Tags|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_$TypeName$(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Tags|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_$TypeName$(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static void Remove_$TypeName$(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable,  Category = "EnTT_UE|Tags|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static void Erase_$TypeName$(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EnTT_UE|Components|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_$TypeName$(UObject* WorldContextObject);
};
