#pragma once

#include <EnTTue_Project/GameModules/FacTD/Core/FacTD_Enums.h>

#include <EnTTue/Include.h>

#include "FacTD_GridComponents.generated.h"

USTRUCT(BlueprintType)
struct FFacTD_GridComponent // APPLY_ENTTUE_REFLECTION()
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FIntVector, int32> GridEntities;
};

USTRUCT(BlueprintType)
struct FFacTD_GridCellComponent // APPLY_ENTTUE_REFLECTION()
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIntVector GridPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIntVector CellSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 OccupantEntity;
};

USTRUCT(BlueprintType)
struct FFacTD_BuildingComponent // APPLY_ENTTUE_REFLECTION()
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 OwningCell;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIntVector BuildingSize;
};

USTRUCT(BlueprintType)
struct FFacTD_DirectionComponent // APPLY_ENTTUE_REFLECTION()
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFacTD_BuildingDirection Direction;
};

USTRUCT(BlueprintType)
struct FFacTD_DirectionDirtyTag // APPLY_ENTTUE_REFLECTION()
{
	GENERATED_BODY()
};
