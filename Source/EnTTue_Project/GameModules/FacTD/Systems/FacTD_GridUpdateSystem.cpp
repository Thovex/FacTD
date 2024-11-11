// Fill out your copyright notice in the Description page of Project Settings.

#include <EnTTue_Project/GameModules/FacTD/Systems/FacTD_GridUpdateSystem.h>

#include <EnTTue/Components/TransformComponents.h>
#include <EnTTue/Components/RenderingComponents.h>
#include <EnTTue/Utils/EntityUtil.h>
#include <EnTTue_Project/GameModules/FacTD/Components/FacTD_BeltComponents.h>
#include <EnTTue_Project/GameModules/FacTD/Components/FacTD_GridComponents.h>
#include <EnTTue_Project/GameModules/FacTD/Utils/FacTD_BuildingUtil.h>

void UFacTD_GridUpdateSystem::Tick(AActor* ActorRoot, FEntityWorld& World, float DeltaTime)
{
	Super::Tick(ActorRoot, World, DeltaTime);

	const EEntity GridRoot = EntityUtil::GetSingletonEntity<FFacTD_GridComponent>(World);

	if (!World.Valid(GridRoot))
	{
		return;
	}
	

	for (auto&& [Entity, Building, Direction] : World.ForEach<FFacTD_BuildingComponent, FFacTD_DirectionComponent, FFacTD_DirectionDirtyTag>())
	{
		World.Erase<FFacTD_DirectionDirtyTag>(Entity);

		FVector ForwardVector = FacTD_BuildingUtil::ConvertBuildingDirection(Direction.Direction);
		
		World.Patch<FRotationComponent>(Entity, [&](FRotationComponent& Rotation)
		{
			Rotation = ForwardVector.Rotation();
		});
	}
}
