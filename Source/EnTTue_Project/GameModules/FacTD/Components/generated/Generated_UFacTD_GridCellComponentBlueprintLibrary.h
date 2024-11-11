#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../FacTD_GridComponents.h"

#include "Generated_UFacTD_GridCellComponentBlueprintLibrary.generated.h"

UCLASS(BlueprintType)
class UFacTD_GridCellComponentWrapper : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_GridCellComponent")
    FFacTD_GridCellComponent& Get() { return *FacTD_GridCellComponent; }

    void Set(FFacTD_GridCellComponent* InFacTD_GridCellComponent) { FacTD_GridCellComponent = InFacTD_GridCellComponent; }
    
private:
    FFacTD_GridCellComponent* FacTD_GridCellComponent;
};

UCLASS(BlueprintType)
class UFacTD_GridCellComponentBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_GridCellComponent", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_FacTD_GridCellComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_GridCellComponent& FacTD_GridCellComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_GridCellComponent", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_FacTD_GridCellComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_GridCellComponent& FacTD_GridCellComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_GridCellComponent", meta = (WorldContext = "WorldContextObject"))
    static void Replace_FacTD_GridCellComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_GridCellComponent& FacTD_GridCellComponent);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_GridCellComponent", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_FacTD_GridCellComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_GridCellComponent", meta = (WorldContext = "WorldContextObject"))
    static UFacTD_GridCellComponentWrapper* TryGet_FacTD_GridCellComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_GridCellComponent", meta = (WorldContext = "WorldContextObject"))
    static void Get_FacTD_GridCellComponent(UObject* WorldContextObject, const int32 EntityId, FFacTD_GridCellComponent& OutFacTD_GridCellComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_GridCellComponent", meta = (WorldContext = "WorldContextObject"))
    static void Remove_FacTD_GridCellComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_GridCellComponent", meta = (WorldContext = "WorldContextObject"))
    static void Erase_FacTD_GridCellComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_GridCellComponent", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_FacTD_GridCellComponent(UObject* WorldContextObject);
   
};
