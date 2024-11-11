#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "../TransformComponents.h"

#include "Generated_UChunkComponentBlueprintLibrary.generated.h"

UCLASS(BlueprintType)
class UChunkComponentWrapper : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|ChunkComponent")
    FChunkComponent& Get() { return *ChunkComponent; }

    void Set(FChunkComponent* InChunkComponent) { ChunkComponent = InChunkComponent; }
    
private:
    FChunkComponent* ChunkComponent;
};

UCLASS(BlueprintType)
class UChunkComponentBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|ChunkComponent", meta = (WorldContext = "WorldContextObject"))
    static void Emplace_ChunkComponent(UObject* WorldContextObject, const int32 EntityId, const FChunkComponent& ChunkComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|ChunkComponent", meta = (WorldContext = "WorldContextObject"))
    static void EmplaceOrReplace_ChunkComponent(UObject* WorldContextObject, const int32 EntityId, const FChunkComponent& ChunkComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|ChunkComponent", meta = (WorldContext = "WorldContextObject"))
    static void Replace_ChunkComponent(UObject* WorldContextObject, const int32 EntityId, const FChunkComponent& ChunkComponent);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|ChunkComponent", meta = (WorldContext = "WorldContextObject"))
    static bool AllOf_ChunkComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|ChunkComponent", meta = (WorldContext = "WorldContextObject"))
    static UChunkComponentWrapper* TryGet_ChunkComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|ChunkComponent", meta = (WorldContext = "WorldContextObject"))
    static void Get_ChunkComponent(UObject* WorldContextObject, const int32 EntityId, FChunkComponent& OutChunkComponent);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|ChunkComponent", meta = (WorldContext = "WorldContextObject"))
    static void Remove_ChunkComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, Category = "EnTT_UE|Components|ChunkComponent", meta = (WorldContext = "WorldContextObject"))
    static void Erase_ChunkComponent(UObject* WorldContextObject, const int32 EntityId);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EnTT_UE|Components|ChunkComponent", meta = (WorldContext = "WorldContextObject"))
    static int32 MetaType_ChunkComponent(UObject* WorldContextObject);
   
};
