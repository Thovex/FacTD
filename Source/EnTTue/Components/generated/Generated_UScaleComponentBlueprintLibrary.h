#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../TransformComponents.h"

#include "Generated_UScaleComponentBlueprintLibrary.generated.h"

UCLASS(BlueprintType)
class UScaleComponentWrapper : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|ScaleComponent")
    FScaleComponent& Get() { return *ScaleComponent; }

    void Set(FScaleComponent* InScaleComponent) { ScaleComponent = InScaleComponent; }
    
private:
    FScaleComponent* ScaleComponent;
};

UCLASS(BlueprintType)
class UScaleComponentBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|ScaleComponent", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_ScaleComponent(UObject* WorldContextObject, const int32 EntityId, const FScaleComponent& ScaleComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|ScaleComponent", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_ScaleComponent(UObject* WorldContextObject, const int32 EntityId, const FScaleComponent& ScaleComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|ScaleComponent", meta = (WorldContext = "WorldContextObject"))
    static void Replace_ScaleComponent(UObject* WorldContextObject, const int32 EntityId, const FScaleComponent& ScaleComponent);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|ScaleComponent", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_ScaleComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|ScaleComponent", meta = (WorldContext = "WorldContextObject"))
    static UScaleComponentWrapper* TryGet_ScaleComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|ScaleComponent", meta = (WorldContext = "WorldContextObject"))
    static void Get_ScaleComponent(UObject* WorldContextObject, const int32 EntityId, FScaleComponent& OutScaleComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|ScaleComponent", meta = (WorldContext = "WorldContextObject"))
    static void Remove_ScaleComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|ScaleComponent", meta = (WorldContext = "WorldContextObject"))
    static void Erase_ScaleComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|ScaleComponent", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_ScaleComponent(UObject* WorldContextObject);
   
};
