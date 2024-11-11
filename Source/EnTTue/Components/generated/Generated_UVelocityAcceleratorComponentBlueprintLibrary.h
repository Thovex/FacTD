#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../TransformComponents.h"

#include "Generated_UVelocityAcceleratorComponentBlueprintLibrary.generated.h"

UCLASS(BlueprintType)
class UVelocityAcceleratorComponentWrapper : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|VelocityAcceleratorComponent")
    FVelocityAcceleratorComponent& Get() { return *VelocityAcceleratorComponent; }

    void Set(FVelocityAcceleratorComponent* InVelocityAcceleratorComponent) { VelocityAcceleratorComponent = InVelocityAcceleratorComponent; }
    
private:
    FVelocityAcceleratorComponent* VelocityAcceleratorComponent;
};

UCLASS(BlueprintType)
class UVelocityAcceleratorComponentBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|VelocityAcceleratorComponent", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_VelocityAcceleratorComponent(UObject* WorldContextObject, const int32 EntityId, const FVelocityAcceleratorComponent& VelocityAcceleratorComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|VelocityAcceleratorComponent", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_VelocityAcceleratorComponent(UObject* WorldContextObject, const int32 EntityId, const FVelocityAcceleratorComponent& VelocityAcceleratorComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|VelocityAcceleratorComponent", meta = (WorldContext = "WorldContextObject"))
    static void Replace_VelocityAcceleratorComponent(UObject* WorldContextObject, const int32 EntityId, const FVelocityAcceleratorComponent& VelocityAcceleratorComponent);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|VelocityAcceleratorComponent", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_VelocityAcceleratorComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|VelocityAcceleratorComponent", meta = (WorldContext = "WorldContextObject"))
    static UVelocityAcceleratorComponentWrapper* TryGet_VelocityAcceleratorComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|VelocityAcceleratorComponent", meta = (WorldContext = "WorldContextObject"))
    static void Get_VelocityAcceleratorComponent(UObject* WorldContextObject, const int32 EntityId, FVelocityAcceleratorComponent& OutVelocityAcceleratorComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|VelocityAcceleratorComponent", meta = (WorldContext = "WorldContextObject"))
    static void Remove_VelocityAcceleratorComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|VelocityAcceleratorComponent", meta = (WorldContext = "WorldContextObject"))
    static void Erase_VelocityAcceleratorComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|VelocityAcceleratorComponent", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_VelocityAcceleratorComponent(UObject* WorldContextObject);
   
};
