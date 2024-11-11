#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../BaseComponents.h"

#include "Generated_ULifeTimeComponentBlueprintLibrary.generated.h"

UCLASS(BlueprintType)
class ULifeTimeComponentWrapper : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|LifeTimeComponent")
    FLifeTimeComponent& Get() { return *LifeTimeComponent; }

    void Set(FLifeTimeComponent* InLifeTimeComponent) { LifeTimeComponent = InLifeTimeComponent; }
    
private:
    FLifeTimeComponent* LifeTimeComponent;
};

UCLASS(BlueprintType)
class ULifeTimeComponentBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|LifeTimeComponent", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_LifeTimeComponent(UObject* WorldContextObject, const int32 EntityId, const FLifeTimeComponent& LifeTimeComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|LifeTimeComponent", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_LifeTimeComponent(UObject* WorldContextObject, const int32 EntityId, const FLifeTimeComponent& LifeTimeComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|LifeTimeComponent", meta = (WorldContext = "WorldContextObject"))
    static void Replace_LifeTimeComponent(UObject* WorldContextObject, const int32 EntityId, const FLifeTimeComponent& LifeTimeComponent);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|LifeTimeComponent", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_LifeTimeComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|LifeTimeComponent", meta = (WorldContext = "WorldContextObject"))
    static ULifeTimeComponentWrapper* TryGet_LifeTimeComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|LifeTimeComponent", meta = (WorldContext = "WorldContextObject"))
    static void Get_LifeTimeComponent(UObject* WorldContextObject, const int32 EntityId, FLifeTimeComponent& OutLifeTimeComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|LifeTimeComponent", meta = (WorldContext = "WorldContextObject"))
    static void Remove_LifeTimeComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|LifeTimeComponent", meta = (WorldContext = "WorldContextObject"))
    static void Erase_LifeTimeComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|LifeTimeComponent", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_LifeTimeComponent(UObject* WorldContextObject);
   
};
