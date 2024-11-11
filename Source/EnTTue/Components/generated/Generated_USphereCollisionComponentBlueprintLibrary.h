#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../CollisionComponents.h"

#include "Generated_USphereCollisionComponentBlueprintLibrary.generated.h"

UCLASS(BlueprintType)
class USphereCollisionComponentWrapper : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|SphereCollisionComponent")
    FSphereCollisionComponent& Get() { return *SphereCollisionComponent; }

    void Set(FSphereCollisionComponent* InSphereCollisionComponent) { SphereCollisionComponent = InSphereCollisionComponent; }
    
private:
    FSphereCollisionComponent* SphereCollisionComponent;
};

UCLASS(BlueprintType)
class USphereCollisionComponentBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|SphereCollisionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_SphereCollisionComponent(UObject* WorldContextObject, const int32 EntityId, const FSphereCollisionComponent& SphereCollisionComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|SphereCollisionComponent", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_SphereCollisionComponent(UObject* WorldContextObject, const int32 EntityId, const FSphereCollisionComponent& SphereCollisionComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|SphereCollisionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Replace_SphereCollisionComponent(UObject* WorldContextObject, const int32 EntityId, const FSphereCollisionComponent& SphereCollisionComponent);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|SphereCollisionComponent", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_SphereCollisionComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|SphereCollisionComponent", meta = (WorldContext = "WorldContextObject"))
    static USphereCollisionComponentWrapper* TryGet_SphereCollisionComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|SphereCollisionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Get_SphereCollisionComponent(UObject* WorldContextObject, const int32 EntityId, FSphereCollisionComponent& OutSphereCollisionComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|SphereCollisionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Remove_SphereCollisionComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|SphereCollisionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Erase_SphereCollisionComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|SphereCollisionComponent", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_SphereCollisionComponent(UObject* WorldContextObject);
   
};
