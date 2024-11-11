#pragma once

#include <EnTTue/Include.h>
#include <EnTTue_Project/GameModules/FacTD/Core/FacTD_Enums.h>

#include "FacTD_BeltComponents.generated.h"

USTRUCT(BlueprintType)
struct FFacTD_BeltItemComponent // APPLY_ENTTUE_REFLECTION()
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector LocalPosition; // Position within the cell (0,0,0) to (1,1,1)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed; // Units per second
};

USTRUCT(BlueprintType)
struct FFacTD_BeltComponent // APPLY_ENTTUE_REFLECTION()
{
	GENERATED_BODY()
	
	bool IsCorner;
	EFacTD_BuildingDirection ExitDirection;
};