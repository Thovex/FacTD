#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../FacTD_GridComponents.h"

#include "Generated_UFacTD_DirectionComponentBlueprintLibrary.generated.h"

UCLASS(BlueprintType)
class UFacTD_DirectionComponentWrapper : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_DirectionComponent")
    FFacTD_DirectionComponent& Get() { return *FacTD_DirectionComponent; }

    void Set(FFacTD_DirectionComponent* InFacTD_DirectionComponent) { FacTD_DirectionComponent = InFacTD_DirectionComponent; }
    
private:
    FFacTD_DirectionComponent* FacTD_DirectionComponent;
};

UCLASS(BlueprintType)
class UFacTD_DirectionComponentBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_DirectionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_FacTD_DirectionComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_DirectionComponent& FacTD_DirectionComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_DirectionComponent", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_FacTD_DirectionComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_DirectionComponent& FacTD_DirectionComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_DirectionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Replace_FacTD_DirectionComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_DirectionComponent& FacTD_DirectionComponent);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_DirectionComponent", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_FacTD_DirectionComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_DirectionComponent", meta = (WorldContext = "WorldContextObject"))
    static UFacTD_DirectionComponentWrapper* TryGet_FacTD_DirectionComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_DirectionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Get_FacTD_DirectionComponent(UObject* WorldContextObject, const int32 EntityId, FFacTD_DirectionComponent& OutFacTD_DirectionComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_DirectionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Remove_FacTD_DirectionComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_DirectionComponent", meta = (WorldContext = "WorldContextObject"))
    static void Erase_FacTD_DirectionComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_DirectionComponent", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_FacTD_DirectionComponent(UObject* WorldContextObject);
   
};
