#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../TransformComponents.h"

#include "Generated_UPositionComponentBlueprintLibrary.generated.h"

UCLASS(BlueprintType)
class UPositionComponentWrapper : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|PositionComponent")
    FPositionComponent& Get() { return *PositionComponent; }

    void Set(FPositionComponent* InPositionComponent) { PositionComponent = InPositionComponent; }
    
private:
    FPositionComponent* PositionComponent;
};

UCLASS(BlueprintType)
class UPositionComponentBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|PositionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_PositionComponent(UObject* WorldContextObject, const int32 EntityId, const FPositionComponent& PositionComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|PositionComponent", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_PositionComponent(UObject* WorldContextObject, const int32 EntityId, const FPositionComponent& PositionComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|PositionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Replace_PositionComponent(UObject* WorldContextObject, const int32 EntityId, const FPositionComponent& PositionComponent);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|PositionComponent", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_PositionComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|PositionComponent", meta = (WorldContext = "WorldContextObject"))
    static UPositionComponentWrapper* TryGet_PositionComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|PositionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Get_PositionComponent(UObject* WorldContextObject, const int32 EntityId, FPositionComponent& OutPositionComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|PositionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Remove_PositionComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|PositionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Erase_PositionComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|PositionComponent", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_PositionComponent(UObject* WorldContextObject);
   
};
