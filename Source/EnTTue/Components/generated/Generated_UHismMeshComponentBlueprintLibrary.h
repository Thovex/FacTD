#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../RenderingComponents.h"

#include "Generated_UHismMeshComponentBlueprintLibrary.generated.h"

UCLASS(BlueprintType)
class UHismMeshComponentWrapper : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|HismMeshComponent")
    FHismMeshComponent& Get() { return *HismMeshComponent; }

    void Set(FHismMeshComponent* InHismMeshComponent) { HismMeshComponent = InHismMeshComponent; }
    
private:
    FHismMeshComponent* HismMeshComponent;
};

UCLASS(BlueprintType)
class UHismMeshComponentBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|HismMeshComponent", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_HismMeshComponent(UObject* WorldContextObject, const int32 EntityId, const FHismMeshComponent& HismMeshComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|HismMeshComponent", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_HismMeshComponent(UObject* WorldContextObject, const int32 EntityId, const FHismMeshComponent& HismMeshComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|HismMeshComponent", meta = (WorldContext = "WorldContextObject"))
    static void Replace_HismMeshComponent(UObject* WorldContextObject, const int32 EntityId, const FHismMeshComponent& HismMeshComponent);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|HismMeshComponent", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_HismMeshComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|HismMeshComponent", meta = (WorldContext = "WorldContextObject"))
    static UHismMeshComponentWrapper* TryGet_HismMeshComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|HismMeshComponent", meta = (WorldContext = "WorldContextObject"))
    static void Get_HismMeshComponent(UObject* WorldContextObject, const int32 EntityId, FHismMeshComponent& OutHismMeshComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|HismMeshComponent", meta = (WorldContext = "WorldContextObject"))
    static void Remove_HismMeshComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|HismMeshComponent", meta = (WorldContext = "WorldContextObject"))
    static void Erase_HismMeshComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|HismMeshComponent", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_HismMeshComponent(UObject* WorldContextObject);
   
};
