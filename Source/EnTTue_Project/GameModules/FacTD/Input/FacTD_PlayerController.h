// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <EnTTue_Project/GameModules/FacTD/Core/FacTD_ExportBuilding.h>

#include <GameFramework/PlayerController.h>

#include "FacTD_PlayerController.generated.h"

USTRUCT(Blueprintable)
struct FBuildingData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AFacTD_ExportBuilding> BuildingConstructor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIntVector BuildingSize = FIntVector(1, 1, 0);
};


/**
 * 
 */
UCLASS(Blueprintable)
class ENTTUE_PROJECT_API AFacTD_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, FBuildingData> BuildingConstructorBlueprint;

	UFUNCTION(BlueprintCallable)
	void TryConstruct(FName BuildingName, const FIntVector& GridPosition, EFacTD_BuildingDirection Direction);

	UFUNCTION(BlueprintCallable)
	void TryDestroy(const FIntVector& GridPosition);

	UFUNCTION(BlueprintCallable)
	void TryRotate(const FIntVector& GridPosition);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIntVector CurrentGridPosition; 
	
protected:
	virtual void Tick(float DeltaSeconds) override;

};
