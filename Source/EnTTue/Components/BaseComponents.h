#pragma once

#include "EnTTue/Include.h"

#include "BaseComponents.generated.h"

USTRUCT(BlueprintType)
struct FNameComponent // APPLY_ENTTUE_REFLECTION()
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FName Name;
};
DEFINE_COMPONENT(FNameComponent);

struct FParentComponent
{
	EEntity Parent;
};

struct FChildrenComponent
{
	TArray<EEntity> Children;
};

USTRUCT(BlueprintType)
struct FLifeTimeComponent // APPLY_ENTTUE_REFLECTION()
{
	GENERATED_BODY()

	float LifeTime;
	bool GenericCallback;
};
