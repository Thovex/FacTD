// Fill out your copyright notice in the Description page of Project Settings.


#include <EnTTue_Project/GameModules/FacTD/Systems/FacTD_InitializerSystem.h>
#include <EnTTue_Project/GameModules/FacTD/Utils/FacTD_InitializerUtil.h>

void UFacTD_InitializerSystem::Init(AActor* ActorRoot, FEntityWorld& World)
{
	Super::Init(ActorRoot, World);

	FacTD_InitializerUtil::InitializeGrid(World, FIntVector2(20, 20), DefaultGridMesh, DefaultGridMaterials);
}

void UFacTD_InitializerSystem::Tick(AActor* ActorRoot, FEntityWorld& World, float DeltaTime)
{
	Super::Tick(ActorRoot, World, DeltaTime);
}
