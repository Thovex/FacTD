// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <EnTTue/Include.h>

#include "EnTTueExportActor.generated.h"

UCLASS(Blueprintable)
class ENTTUE_API AEnTTueExportActor : public AActor
{
	GENERATED_BODY()

public:
	AEnTTueExportActor();

	UFUNCTION(BlueprintImplementableEvent)
	void Export_Implementation(int32 CreatedEntity);

	virtual void Export(int32 CreatedEntity);

protected:
	virtual void BeginPlay() override;
};
