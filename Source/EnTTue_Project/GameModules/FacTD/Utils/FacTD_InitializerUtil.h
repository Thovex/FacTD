// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <EnTTue/EntityWorld.h>

#include "CoreMinimal.h"
#include <Kismet/BlueprintFunctionLibrary.h>
#include "FacTD_InitializerUtil.generated.h"

/**
 * 
 */
UCLASS()
class ENTTUE_PROJECT_API UFacTD_InitializerUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
};

namespace FacTD_InitializerUtil
{
	void InitializeGrid(FEntityWorld& World, FIntVector2 GridSize, UStaticMesh* DefaultGridMesh, TArray<UMaterialInterface*> DefaultGridMaterials);
	EEntity CreateGridCell(FEntityWorld& World, EEntity GridRootEntity, const FIntVector& Position);
}
