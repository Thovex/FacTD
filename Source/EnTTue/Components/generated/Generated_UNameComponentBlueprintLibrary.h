#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../BaseComponents.h"

#include "Generated_UNameComponentBlueprintLibrary.generated.h"

UCLASS(BlueprintType)
class UNameComponentWrapper : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|NameComponent")
    FNameComponent& Get() { return *NameComponent; }

    void Set(FNameComponent* InNameComponent) { NameComponent = InNameComponent; }
    
private:
    FNameComponent* NameComponent;
};

UCLASS(BlueprintType)
class UNameComponentBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|NameComponent", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_NameComponent(UObject* WorldContextObject, const int32 EntityId, const FNameComponent& NameComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|NameComponent", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_NameComponent(UObject* WorldContextObject, const int32 EntityId, const FNameComponent& NameComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|NameComponent", meta = (WorldContext = "WorldContextObject"))
    static void Replace_NameComponent(UObject* WorldContextObject, const int32 EntityId, const FNameComponent& NameComponent);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|NameComponent", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_NameComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|NameComponent", meta = (WorldContext = "WorldContextObject"))
    static UNameComponentWrapper* TryGet_NameComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|NameComponent", meta = (WorldContext = "WorldContextObject"))
    static void Get_NameComponent(UObject* WorldContextObject, const int32 EntityId, FNameComponent& OutNameComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|NameComponent", meta = (WorldContext = "WorldContextObject"))
    static void Remove_NameComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|NameComponent", meta = (WorldContext = "WorldContextObject"))
    static void Erase_NameComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|NameComponent", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_NameComponent(UObject* WorldContextObject);
   
};
