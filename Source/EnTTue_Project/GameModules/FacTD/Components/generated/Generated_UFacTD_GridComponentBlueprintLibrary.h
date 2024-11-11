#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../FacTD_GridComponents.h"

#include "Generated_UFacTD_GridComponentBlueprintLibrary.generated.h"

UCLASS(BlueprintType)
class UFacTD_GridComponentWrapper : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_GridComponent")
    FFacTD_GridComponent& Get() { return *FacTD_GridComponent; }

    void Set(FFacTD_GridComponent* InFacTD_GridComponent) { FacTD_GridComponent = InFacTD_GridComponent; }
    
private:
    FFacTD_GridComponent* FacTD_GridComponent;
};

UCLASS(BlueprintType)
class UFacTD_GridComponentBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_GridComponent", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_FacTD_GridComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_GridComponent& FacTD_GridComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_GridComponent", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_FacTD_GridComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_GridComponent& FacTD_GridComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_GridComponent", meta = (WorldContext = "WorldContextObject"))
    static void Replace_FacTD_GridComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_GridComponent& FacTD_GridComponent);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_GridComponent", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_FacTD_GridComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_GridComponent", meta = (WorldContext = "WorldContextObject"))
    static UFacTD_GridComponentWrapper* TryGet_FacTD_GridComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_GridComponent", meta = (WorldContext = "WorldContextObject"))
    static void Get_FacTD_GridComponent(UObject* WorldContextObject, const int32 EntityId, FFacTD_GridComponent& OutFacTD_GridComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_GridComponent", meta = (WorldContext = "WorldContextObject"))
    static void Remove_FacTD_GridComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_GridComponent", meta = (WorldContext = "WorldContextObject"))
    static void Erase_FacTD_GridComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_GridComponent", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_FacTD_GridComponent(UObject* WorldContextObject);
   
};
