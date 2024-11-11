#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../FacTD_BeltComponents.h"

#include "Generated_UFacTD_BeltComponentBlueprintLibrary.generated.h"

UCLASS(BlueprintType)
class UFacTD_BeltComponentWrapper : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_BeltComponent")
    FFacTD_BeltComponent& Get() { return *FacTD_BeltComponent; }

    void Set(FFacTD_BeltComponent* InFacTD_BeltComponent) { FacTD_BeltComponent = InFacTD_BeltComponent; }
    
private:
    FFacTD_BeltComponent* FacTD_BeltComponent;
};

UCLASS(BlueprintType)
class UFacTD_BeltComponentBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_BeltComponent", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_FacTD_BeltComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_BeltComponent& FacTD_BeltComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_BeltComponent", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_FacTD_BeltComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_BeltComponent& FacTD_BeltComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_BeltComponent", meta = (WorldContext = "WorldContextObject"))
    static void Replace_FacTD_BeltComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_BeltComponent& FacTD_BeltComponent);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_BeltComponent", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_FacTD_BeltComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_BeltComponent", meta = (WorldContext = "WorldContextObject"))
    static UFacTD_BeltComponentWrapper* TryGet_FacTD_BeltComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_BeltComponent", meta = (WorldContext = "WorldContextObject"))
    static void Get_FacTD_BeltComponent(UObject* WorldContextObject, const int32 EntityId, FFacTD_BeltComponent& OutFacTD_BeltComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_BeltComponent", meta = (WorldContext = "WorldContextObject"))
    static void Remove_FacTD_BeltComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_BeltComponent", meta = (WorldContext = "WorldContextObject"))
    static void Erase_FacTD_BeltComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_BeltComponent", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_FacTD_BeltComponent(UObject* WorldContextObject);
   
};
