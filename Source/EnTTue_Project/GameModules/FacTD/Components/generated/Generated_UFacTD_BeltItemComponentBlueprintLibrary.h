#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../FacTD_BeltComponents.h"

#include "Generated_UFacTD_BeltItemComponentBlueprintLibrary.generated.h"

UCLASS(BlueprintType)
class UFacTD_BeltItemComponentWrapper : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_BeltItemComponent")
    FFacTD_BeltItemComponent& Get() { return *FacTD_BeltItemComponent; }

    void Set(FFacTD_BeltItemComponent* InFacTD_BeltItemComponent) { FacTD_BeltItemComponent = InFacTD_BeltItemComponent; }
    
private:
    FFacTD_BeltItemComponent* FacTD_BeltItemComponent;
};

UCLASS(BlueprintType)
class UFacTD_BeltItemComponentBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_BeltItemComponent", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_FacTD_BeltItemComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_BeltItemComponent& FacTD_BeltItemComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_BeltItemComponent", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_FacTD_BeltItemComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_BeltItemComponent& FacTD_BeltItemComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_BeltItemComponent", meta = (WorldContext = "WorldContextObject"))
    static void Replace_FacTD_BeltItemComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_BeltItemComponent& FacTD_BeltItemComponent);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_BeltItemComponent", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_FacTD_BeltItemComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_BeltItemComponent", meta = (WorldContext = "WorldContextObject"))
    static UFacTD_BeltItemComponentWrapper* TryGet_FacTD_BeltItemComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_BeltItemComponent", meta = (WorldContext = "WorldContextObject"))
    static void Get_FacTD_BeltItemComponent(UObject* WorldContextObject, const int32 EntityId, FFacTD_BeltItemComponent& OutFacTD_BeltItemComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_BeltItemComponent", meta = (WorldContext = "WorldContextObject"))
    static void Remove_FacTD_BeltItemComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|FacTD_BeltItemComponent", meta = (WorldContext = "WorldContextObject"))
    static void Erase_FacTD_BeltItemComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|FacTD_BeltItemComponent", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_FacTD_BeltItemComponent(UObject* WorldContextObject);
   
};
