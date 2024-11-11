#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "EnTTueBlueprintLibrary.generated.h"

UCLASS(Blueprintable)
class ENTTUE_API UEnTTueBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "EnTTue|ECS", meta = (WorldContext = "WorldContextObject"))
	static int32 CreateEmptyEntity(UObject* WorldContextObject);
	
	UFUNCTION(BlueprintCallable, Category = "EnTTue|ECS", meta = (WorldContext = "WorldContextObject"))
	static int32 CreateNamedEntity(UObject* WorldContextObject, const FName& Name);
	
	UFUNCTION(BlueprintCallable, Category = "EnTTue|ECS", meta = (WorldContext = "WorldContextObject"))
	static int32 CreateEntity(UObject* WorldContextObject, const FName& Name, const FTransform& Transform);

	UFUNCTION(BlueprintCallable, Category = "EnTTue|ECS", meta = (WorldContext = "WorldContextObject"))
	static int32 CreateEntityWithParent(UObject* WorldContextObject, const FName& Name, int32 ParentEntityId, const FTransform& Transform);
	
	UFUNCTION(BlueprintCallable, Category = "EnTTue|ECS", meta = (WorldContext = "WorldContextObject"))
	static bool IsValid(UObject* WorldContextObject, int32 EntityId);
	
	UFUNCTION(BlueprintCallable, Category = "EnTTue|ECS", meta = (WorldContext = "WorldContextObject"))
	static int32 FindChildWithComponent(UObject* WorldContextObject, int32 EntityId, UStruct* ComponentType, bool IncludeRoot);
};

	