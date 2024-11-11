#pragma once

#include <EnTTue_Project/GameModules/FacTD/Core/FacTD_Enums.h>
#include "FacTD_ResourceComponents.generated.h"

USTRUCT(BlueprintType)
struct FFacTD_ResourceNodeComponent
{
	GENERATED_BODY()

	EFacTD_ResourceType ResourceType;
	int32 ResourceAmount = -1; // -1 means infinite
};

USTRUCT(BlueprintType)
struct FFacTD_ResourceNodeGathererComponent
{
	GENERATED_BODY()

	EFacTD_ResourceType GatheredResourceType;

	static float GetRadius(FEntityWorld& World, EEntity Entity)
	{
		return 1000.f;
	}

	static float GetGatherRate(FEntityWorld& World, EEntity Entity)
	{
		return 1.f; // 1 resource per second
	}
};