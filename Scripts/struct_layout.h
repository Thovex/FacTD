#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

$IncludePath$

#include "Generated_U$TypeName$BlueprintLibrary.generated.h"

UCLASS(BlueprintType)
class U$TypeName$Wrapper : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|$TypeName$")
    F$TypeName$& Get() { return *$TypeName$; }

    void Set(F$TypeName$* In$TypeName$) { $TypeName$ = In$TypeName$; }
    
private:
    F$TypeName$* $TypeName$;
};

UCLASS(BlueprintType)
class U$TypeName$BlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_$TypeName$(UObject* WorldContextObject, const int32 EntityId, const F$TypeName$& $TypeName$);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_$TypeName$(UObject* WorldContextObject, const int32 EntityId, const F$TypeName$& $TypeName$);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static void Replace_$TypeName$(UObject* WorldContextObject, const int32 EntityId, const F$TypeName$& $TypeName$);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_$TypeName$(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static U$TypeName$Wrapper* TryGet_$TypeName$(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static void Get_$TypeName$(UObject* WorldContextObject, const int32 EntityId, F$TypeName$& Out$TypeName$);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static void Remove_$TypeName$(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static void Erase_$TypeName$(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_$TypeName$(UObject* WorldContextObject);
   
};
