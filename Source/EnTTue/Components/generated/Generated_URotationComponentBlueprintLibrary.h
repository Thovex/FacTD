#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../TransformComponents.h"

#include "Generated_URotationComponentBlueprintLibrary.generated.h"

UCLASS(BlueprintType)
class URotationComponentWrapper : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|RotationComponent")
    FRotationComponent& Get() { return *RotationComponent; }

    void Set(FRotationComponent* InRotationComponent) { RotationComponent = InRotationComponent; }
    
private:
    FRotationComponent* RotationComponent;
};

UCLASS(BlueprintType)
class URotationComponentBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|RotationComponent", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_RotationComponent(UObject* WorldContextObject, const int32 EntityId, const FRotationComponent& RotationComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|RotationComponent", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_RotationComponent(UObject* WorldContextObject, const int32 EntityId, const FRotationComponent& RotationComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|RotationComponent", meta = (WorldContext = "WorldContextObject"))
    static void Replace_RotationComponent(UObject* WorldContextObject, const int32 EntityId, const FRotationComponent& RotationComponent);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|RotationComponent", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_RotationComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|RotationComponent", meta = (WorldContext = "WorldContextObject"))
    static URotationComponentWrapper* TryGet_RotationComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|RotationComponent", meta = (WorldContext = "WorldContextObject"))
    static void Get_RotationComponent(UObject* WorldContextObject, const int32 EntityId, FRotationComponent& OutRotationComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|RotationComponent", meta = (WorldContext = "WorldContextObject"))
    static void Remove_RotationComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|RotationComponent", meta = (WorldContext = "WorldContextObject"))
    static void Erase_RotationComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|RotationComponent", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_RotationComponent(UObject* WorldContextObject);
   
};
