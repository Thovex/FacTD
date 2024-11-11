#pragma once

#include "EnTTue/Include.h"

#include "EnTTueEvents.generated.h"

USTRUCT(BlueprintType)
struct FGenericEvent {
	GENERATED_BODY()
	
	EEntity Target;
};

struct FDamageNumberEvent {
	FVector WorldPosition;
	float Damage;
};

USTRUCT(BlueprintType)
struct FEventTarget
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Actor = -1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<int32> Targets;
};