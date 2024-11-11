#pragma once

#include <EnTTue/Components/EnTTueEvents.h>

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

USTRUCT(BlueprintType)
struct F$TypeName$WithTarget
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    F$TypeName$ $TypeName$;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FEventTarget Target;
};

UCLASS(BlueprintType)
class U$TypeName$BlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_$TypeName$(UObject* WorldContextObject);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static void OnEvent_$TypeName$(UObject* WorldContextObject, TArray<F$TypeName$>& $TypeName$);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static void OnEvent_Targeted_$TypeName$(UObject* WorldContextObject, TArray<F$TypeName$WithTarget>& $TypeName$);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static void OnEvent_TargetedTo_$TypeName$(UObject* WorldContextObject, int32 TargetEntity, TArray<F$TypeName$WithTarget>& $TypeName$);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static void Emit_$TypeName$(UObject* WorldContextObject, const F$TypeName$& $TypeName$);
    
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|$TypeName$", meta = (WorldContext = "WorldContextObject"))
    static void Emit_Targeted_$TypeName$(UObject* WorldContextObject, const F$TypeName$& $TypeName$, const FEventTarget& Target);
   
};
