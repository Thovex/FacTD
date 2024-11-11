// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <EnTTue/Systems/System.h>
#include <EnTTue_Project/GameModules/FacTD/Core/FacTD_Enums.h>

#include "FacTD_GridUpdateSystem.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ENTTUE_PROJECT_API UFacTD_GridUpdateSystem : public USystem
{
	GENERATED_BODY()

protected:
	virtual void Tick(AActor* ActorRoot, FEntityWorld& World, float DeltaTime) override;
};
