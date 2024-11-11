#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../RenderingComponents.h"

#include "Generated_USkMeshComponentBlueprintLibrary.generated.h"

UCLASS(BlueprintType)
class USkMeshComponentWrapper : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|SkMeshComponent")
    FSkMeshComponent& Get() { return *SkMeshComponent; }

    void Set(FSkMeshComponent* InSkMeshComponent) { SkMeshComponent = InSkMeshComponent; }
    
private:
    FSkMeshComponent* SkMeshComponent;
};

UCLASS(BlueprintType)
class USkMeshComponentBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|SkMeshComponent", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_SkMeshComponent(UObject* WorldContextObject, const int32 EntityId, const FSkMeshComponent& SkMeshComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|SkMeshComponent", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_SkMeshComponent(UObject* WorldContextObject, const int32 EntityId, const FSkMeshComponent& SkMeshComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|SkMeshComponent", meta = (WorldContext = "WorldContextObject"))
    static void Replace_SkMeshComponent(UObject* WorldContextObject, const int32 EntityId, const FSkMeshComponent& SkMeshComponent);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|SkMeshComponent", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_SkMeshComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|SkMeshComponent", meta = (WorldContext = "WorldContextObject"))
    static USkMeshComponentWrapper* TryGet_SkMeshComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|SkMeshComponent", meta = (WorldContext = "WorldContextObject"))
    static void Get_SkMeshComponent(UObject* WorldContextObject, const int32 EntityId, FSkMeshComponent& OutSkMeshComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|SkMeshComponent", meta = (WorldContext = "WorldContextObject"))
    static void Remove_SkMeshComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|SkMeshComponent", meta = (WorldContext = "WorldContextObject"))
    static void Erase_SkMeshComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|SkMeshComponent", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_SkMeshComponent(UObject* WorldContextObject);
   
};
