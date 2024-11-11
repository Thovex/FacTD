#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../CollisionComponents.h"

#include "Generated_UBoxCollisionComponentBlueprintLibrary.generated.h"

UCLASS(BlueprintType)
class UBoxCollisionComponentWrapper : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|BoxCollisionComponent")
    FBoxCollisionComponent& Get() { return *BoxCollisionComponent; }

    void Set(FBoxCollisionComponent* InBoxCollisionComponent) { BoxCollisionComponent = InBoxCollisionComponent; }
    
private:
    FBoxCollisionComponent* BoxCollisionComponent;
};

UCLASS(BlueprintType)
class UBoxCollisionComponentBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|BoxCollisionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_BoxCollisionComponent(UObject* WorldContextObject, const int32 EntityId, const FBoxCollisionComponent& BoxCollisionComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|BoxCollisionComponent", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_BoxCollisionComponent(UObject* WorldContextObject, const int32 EntityId, const FBoxCollisionComponent& BoxCollisionComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|BoxCollisionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Replace_BoxCollisionComponent(UObject* WorldContextObject, const int32 EntityId, const FBoxCollisionComponent& BoxCollisionComponent);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|BoxCollisionComponent", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_BoxCollisionComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|BoxCollisionComponent", meta = (WorldContext = "WorldContextObject"))
    static UBoxCollisionComponentWrapper* TryGet_BoxCollisionComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|BoxCollisionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Get_BoxCollisionComponent(UObject* WorldContextObject, const int32 EntityId, FBoxCollisionComponent& OutBoxCollisionComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|BoxCollisionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Remove_BoxCollisionComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|BoxCollisionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Erase_BoxCollisionComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|BoxCollisionComponent", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_BoxCollisionComponent(UObject* WorldContextObject);
   
};
