// Fill out your copyright notice in the Description page of Project Settings.

#include <EnTTue_Project/GameModules/FacTD/Utils/FacTD_InitializerUtil.h>
#include <EnTTue_Project/GameModules/FacTD/Components/FacTD_GridComponents.h>

#include <EnTTue/Utils/EntityBuilderUtil.h>
#include <EnTTue/Components/RenderingComponents.h>
#include <EnTTue/Utils/EntityUtil.h>

void FacTD_InitializerUtil::InitializeGrid(FEntityWorld& World, FIntVector2 GridSize, UStaticMesh* DefaultGridMesh, TArray<UMaterialInterface*> DefaultGridMaterials)
{
	EEntity GridRootEntity = EntityBuilderUtil::CreateEntity(World, FName("GridRoot"), FTransform::Identity);
	auto& GridComp = World.Emplace<FFacTD_GridComponent>(GridRootEntity);
	
	EntityUtil::AddSingletonEntity(World, FName("GridRoot"), GridRootEntity);

	for (int32 x = 0; x < GridSize.X ; x++)
	{
		for (int32 y = 0; y < GridSize.Y; y++)
		{
			FIntVector Position(x, y, 0);
			EEntity GridCellEntity = FacTD_InitializerUtil::CreateGridCell(World, GridRootEntity, Position);
      
			World.Emplace<FHismMeshComponent>(GridCellEntity, FHismMeshComponent {
			   .Mesh = DefaultGridMesh,
			   .Materials = DefaultGridMaterials,
			   .CollisionChannel = TERRAIN_TRACE_CHANNEL,
			});
      
			GridComp.GridEntities.Add(Position, EntityUtil::ToInt32(GridCellEntity));
		}
	}

}

EEntity FacTD_InitializerUtil::CreateGridCell(FEntityWorld& World, EEntity GridRootEntity, const FIntVector& Position)
{
	FString Name = FString::Printf(TEXT("Cell%d_%d"), Position.X, Position.Y);

	static UStaticMesh* DefaultGridMesh = nullptr;
	static TArray<UMaterialInterface*> DefaultGridMaterials;

	// Load assets only once
	if (!DefaultGridMesh || !DefaultGridMaterials.IsEmpty())
	{
		DefaultGridMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
		auto* DefaultGridMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Script/Engine.Material'/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial'"));
		DefaultGridMaterials = { DefaultGridMaterial };

		if (!DefaultGridMesh || !DefaultGridMaterial)
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to load grid cell assets"));
			return entt::null;
		}
	}
    
	EEntity GridCellEntity = EntityBuilderUtil::CreateEntity(World, FName(*Name), GridRootEntity, FTransform(FVector(Position.X * 100, Position.Y * 100, 0)));
	World.Emplace<FFacTD_GridCellComponent>(GridCellEntity, FFacTD_GridCellComponent {
		.GridPosition = Position,
		.OccupantEntity = EntityUtil::ToInt32(entt::null),
	});
    
	World.Emplace<FHismMeshComponent>(GridCellEntity, FHismMeshComponent {
	   .Mesh = DefaultGridMesh,
	   .Materials = DefaultGridMaterials,
	   .CollisionChannel = TERRAIN_TRACE_CHANNEL,
	});
    
	return GridCellEntity;
}
