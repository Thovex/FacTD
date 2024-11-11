// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <EnTTue_Project/GameModules/FacTD/Core/FacTD_Enums.h>

#include "CoreMinimal.h"
#include <Kismet/BlueprintFunctionLibrary.h>
#include "FacTD_BuildingUtil.generated.h"

/**
 * 
 */
UCLASS()
class ENTTUE_PROJECT_API UFacTD_BuildingUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "FacTD|BuildingUtil")
	static FVector ConvertBuildingDirection(const EFacTD_BuildingDirection& Direction);
};

namespace FacTD_BuildingUtil
{
	FVector ConvertBuildingDirection(const EFacTD_BuildingDirection& Direction);
}