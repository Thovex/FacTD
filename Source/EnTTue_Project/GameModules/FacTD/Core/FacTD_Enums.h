#pragma once

#include "EnTTue/Include.h"
#include "FacTD_Enums.generated.h"

UENUM(BlueprintType)
enum class EFacTD_ResourceType : uint8
{
	EFacTD_Resource_None = 0 UMETA(DisplayName = "None"),
	EFacTD_Resource_Money = 1 UMETA(DisplayName = "Money"),
	EFacTD_Resource_Wood = 2 UMETA(DisplayName = "Wood"),
	EFacTD_Resource_Stone = 3 UMETA(DisplayName = "Stone"),
	EFacTD_Resource_Iron = 4 UMETA(DisplayName = "Iron"),
	EFacTD_Resource_Coal = 5 UMETA(DisplayName = "Coal"),
	EFacTD_Resource_Gold = 6 UMETA(DisplayName = "Gold"),
	EFacTD_Resource_Diamond = 7 UMETA(DisplayName = "Diamond"),
};


UENUM(BlueprintType)
enum class EFacTD_BuildingDirection : uint8
{
	EFacTD_BuildingDirection_Up = 0 UMETA(DisplayName = "Up"),
	EFacTD_BuildingDirection_Right = 1 UMETA(DisplayName = "Right"),
	EFacTD_BuildingDirection_Down = 2 UMETA(DisplayName = "Down"),
	EFacTD_BuildingDirection_Left = 3 UMETA(DisplayName = "Left"),
};