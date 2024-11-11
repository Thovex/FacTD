#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../FacTD_GridComponents.h"

#include "Generated_UFacTD_BuildingComponentBlueprintLibrary.generated.h"

UCLASS(BlueprintType)
class UFacTD_BuildingComponentWrapper : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_BuildingComponent")
    FFacTD_BuildingComponent& Get() { return *FacTD_BuildingComponent; }

    void Set(FFacTD_BuildingComponent* InFacTD_BuildingComponent) { FacTD_BuildingComponent = InFacTD_BuildingComponent; }
    
private:
    FFacTD_BuildingComponent* FacTD_BuildingComponent;
};

UCLASS(BlueprintType)
class UFacTD_BuildingComponentBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_BuildingComponent", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_FacTD_BuildingComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_BuildingComponent& FacTD_BuildingComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_BuildingComponent", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_FacTD_BuildingComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_BuildingComponent& FacTD_BuildingComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_BuildingComponent", meta = (WorldContext = "WorldContextObject"))
    static void Replace_FacTD_BuildingComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_BuildingComponent& FacTD_BuildingComponent);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_BuildingComponent", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_FacTD_BuildingComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_BuildingComponent", meta = (WorldContext = "WorldContextObject"))
    static UFacTD_BuildingComponentWrapper* TryGet_FacTD_BuildingComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_BuildingComponent", meta = (WorldContext = "WorldContextObject"))
    static void Get_FacTD_BuildingComponent(UObject* WorldContextObject, const int32 EntityId, FFacTD_BuildingComponent& OutFacTD_BuildingComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_BuildingComponent", meta = (WorldContext = "WorldContextObject"))
    static void Remove_FacTD_BuildingComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_BuildingComponent", meta = (WorldContext = "WorldContextObject"))
    static void Erase_FacTD_BuildingComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_BuildingComponent", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_FacTD_BuildingComponent(UObject* WorldContextObject);
   
};
