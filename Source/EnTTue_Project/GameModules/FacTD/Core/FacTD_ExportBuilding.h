// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <EnTTue/UnrealFrameworks/EnTTueExportActor.h>
#include <EnTTue_Project/GameModules/FacTD/Components/FacTD_GridComponents.h>

#include "FacTD_ExportBuilding.generated.h"

UCLASS(Blueprintable)
class ENTTUE_PROJECT_API AFacTD_ExportBuilding : public AEnTTueExportActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 GridRootEntity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FFacTD_DirectionComponent DirectionComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIntVector BuildingSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CenterLocation;

};
