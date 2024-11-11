#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../TransformComponents.h"

#include "Generated_UVelocityComponentBlueprintLibrary.generated.h"

UCLASS(BlueprintType)
class UVelocityComponentWrapper : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|VelocityComponent")
    FVelocityComponent& Get() { return *VelocityComponent; }

    void Set(FVelocityComponent* InVelocityComponent) { VelocityComponent = InVelocityComponent; }
    
private:
    FVelocityComponent* VelocityComponent;
};

UCLASS(BlueprintType)
class UVelocityComponentBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|VelocityComponent", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_VelocityComponent(UObject* WorldContextObject, const int32 EntityId, const FVelocityComponent& VelocityComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|VelocityComponent", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_VelocityComponent(UObject* WorldContextObject, const int32 EntityId, const FVelocityComponent& VelocityComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|VelocityComponent", meta = (WorldContext = "WorldContextObject"))
    static void Replace_VelocityComponent(UObject* WorldContextObject, const int32 EntityId, const FVelocityComponent& VelocityComponent);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|VelocityComponent", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_VelocityComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|VelocityComponent", meta = (WorldContext = "WorldContextObject"))
    static UVelocityComponentWrapper* TryGet_VelocityComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|VelocityComponent", meta = (WorldContext = "WorldContextObject"))
    static void Get_VelocityComponent(UObject* WorldContextObject, const int32 EntityId, FVelocityComponent& OutVelocityComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|VelocityComponent", meta = (WorldContext = "WorldContextObject"))
    static void Remove_VelocityComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|VelocityComponent", meta = (WorldContext = "WorldContextObject"))
    static void Erase_VelocityComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|VelocityComponent", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_VelocityComponent(UObject* WorldContextObject);
   
};
