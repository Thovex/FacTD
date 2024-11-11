// Fill out your copyright notice in the Description page of Project Settings.

#include <EnTTue_Project/GameModules/FacTD/Input/FacTD_PlayerController.h>

#include <EnTTue/Utils/EntityUtil.h>
#include <EnTTue/Components/Tags.h>

#include <EnTTue_Project/GameModules/FacTD/Components/FacTD_GridComponents.h>
#include <EnTTue_Project/GameModules/FacTD/Utils/FacTD_InitializerUtil.h>

void AFacTD_PlayerController::TryConstruct(FName BuildingName, const FIntVector& GridPosition, EFacTD_BuildingDirection Direction)
{
    UWorld* UnrealWorld = GetWorld();
    FEntityWorld& World = EntityUtil::GetEntityWorld(this);

    EEntity GridRootEntity = EntityUtil::GetSingletonEntity<FFacTD_GridComponent>(World);
    auto& GridComp = World.Get<FFacTD_GridComponent>(GridRootEntity);

    bool bAnyError = false;

    UE_LOG(LogTemp, Warning, TEXT("Constructing %s at position %s"), *BuildingName.ToString(), *GridPosition.ToString());

    if (!GridComp.GridEntities.Contains(GridPosition))
    {
        UE_LOG(LogTemp, Warning, TEXT("No grid cell at position %s"), *GridPosition.ToString());
        bAnyError = true;
    }

    auto& [BuildingConstructor, BuildingSize] = BuildingConstructorBlueprint[BuildingName];

    // Check if BuildingSize is within GridEntities bounds:
    for (int32 x = 0; x < BuildingSize.X; x++)
    {
        for (int32 y = 0; y < BuildingSize.Y; y++)
        {
            FIntVector CurrentCellCoordinate = GridPosition + FIntVector(x, y, 0);

            if (!GridComp.GridEntities.Contains(CurrentCellCoordinate))
            {
                bAnyError = true;
                continue; // Skip the rest of the loop if out of bounds
            }

            // Check if the cell is occupied
            EEntity CellEntity = EntityUtil::ToEntity(GridComp.GridEntities[CurrentCellCoordinate]);
            if (World.AllOf<FFacTD_BuildingComponent>(CellEntity))
            {
                DrawDebugBox(GetWorld(), FVector(CurrentCellCoordinate.X * 100, CurrentCellCoordinate.Y * 100, 100.f), FVector(51, 51, 51), FColor::Red, false, 2.f);
                UE_LOG(LogTemp, Warning, TEXT("Building %s is occupied at position %s"), *BuildingName.ToString(), *CurrentCellCoordinate.ToString());
                bAnyError = true;
            }
        }
    }

    if (bAnyError)
    {
        return;
    }

    EEntity OwningCellEntity = EntityUtil::ToEntity(GridComp.GridEntities[GridPosition]);

	// Step 1. If our building is > 1x1: We need to destroy all 'Cells' and replace them with a new 'Merged Cell'

	for (int32 x = 0; x < BuildingSize.X; x++)
	{
		for (int32 y = 0; y < BuildingSize.Y; y++)
		{
			FIntVector CurrentCellCoordinate = GridPosition + FIntVector(x, y, 0);
			if (CurrentCellCoordinate != GridPosition)
			{
				EEntity CurrentCellEntity = EntityUtil::ToEntity(GridComp.GridEntities[CurrentCellCoordinate]);
				World.EmplaceOrReplace<FDestroyAtEndOfTickTag>(CurrentCellEntity);
				GridComp.GridEntities.Emplace(CurrentCellCoordinate, EntityUtil::ToInt32(OwningCellEntity));
			}
		}
	}

	// Step 2.

	/* 
    FVector CenterLocation = FVector((BuildingSize.X / 2.f) * 100.f, (BuildingSize.Y / 2.f) * 100.f, 50.f);
    CenterLocation -= FVector(50, 50, 0);

    UE_LOG(LogTemp, Warning, TEXT("Owning Entity: %s"), *World.Get<FNameComponent>(OwningCellEntity).Name.ToString());

    AFacTD_ExportBuilding* SpawnedBlueprint = UnrealWorld->SpawnActorDeferred<AFacTD_ExportBuilding>(BuildingConstructor, FTransform::Identity);
    SpawnedBlueprint->GridRootEntity = EntityUtil::ToInt32(GridRootEntity);
    SpawnedBlueprint->BuildingSize = BuildingSize;
    SpawnedBlueprint->DirectionComponent = FFacTD_DirectionComponent{ .Direction = Direction };
    SpawnedBlueprint->CenterLocation = CenterLocation;
    SpawnedBlueprint->FinishSpawning(FTransform(CenterLocation));

    FTransform SpawnTransform = FTransform(CenterLocation);
    SpawnTransform.SetScale3D(FVector(BuildingSize.X, BuildingSize.Y, 1.f));
    
    // Merge cells, keep GridRootEntity as the Owner - so destroy everything bar that, then update GridEntities with the single "Owning Cell"
    for (int32 x = 0; x < BuildingSize.X; x++)
	{
		for (int32 y = 0; y < BuildingSize.Y; y++)
		{
			FIntVector CurrentCellCoordinate = GridPosition + FIntVector(x, y, 0);
			if (CurrentCellCoordinate != GridPosition)
			{
				EEntity CurrentCellEntity = EntityUtil::ToEntity(GridComp.GridEntities[CurrentCellCoordinate]);
				World.EmplaceOrReplace<FDestroyAtEndOfTickTag>(CurrentCellEntity);
				GridComp.GridEntities.Emplace(CurrentCellCoordinate, EntityUtil::ToInt32(OwningCellEntity));
			}
		}
	}

    // Update the owning cell
    World.Emplace<FFacTD_BuildingComponent>(OwningCellEntity, FFacTD_BuildingComponent {
    	.OwningCell = EntityUtil::ToInt32(OwningCellEntity),
    	.BuildingSize = BuildingSize,
    });
    World.Emplace<FFacTD_DirectionComponent>(OwningCellEntity, FFacTD_DirectionComponent{
    	.Direction = Direction
    });
    World.Emplace<FFacTD_DirectionDirtyTag>(OwningCellEntity);

    SpawnedBlueprint->Export(EntityUtil::ToInt32(OwningCellEntity));
    SpawnedBlueprint->Destroy();

    */
}

void AFacTD_PlayerController::TryDestroy(const FIntVector& GridPosition)
{
    FEntityWorld& World = EntityUtil::GetEntityWorld(this);

    EEntity GridRootEntity = EntityUtil::GetSingletonEntity<FFacTD_GridComponent>(World);
    auto& GridComp = World.Get<FFacTD_GridComponent>(GridRootEntity);

    if (!GridComp.GridEntities.Contains(GridPosition))
    {
       UE_LOG(LogTemp, Warning, TEXT("No grid cell at position %s"), *GridPosition.ToString());
       return;
    }

    EEntity CellEntity = EntityUtil::ToEntity(GridComp.GridEntities[GridPosition]);
    
    if (!World.AllOf<FFacTD_BuildingComponent>(CellEntity))
    {
       UE_LOG(LogTemp, Warning, TEXT("No building at position %s"), *GridPosition.ToString());
       return;
    }

    auto& BuildingComp = World.Get<FFacTD_BuildingComponent>(CellEntity);
    FIntVector BuildingSize = BuildingComp.BuildingSize;

    // Re-create the grid cells
    for (int32 x = 0; x < BuildingSize.X; x++)
    {
        for (int32 y = 0; y < BuildingSize.Y; y++)
        {
            FIntVector CurrentCellCoordinate = GridPosition + FIntVector(x, y, 0);
            if (CurrentCellCoordinate != GridPosition)
            {
                EEntity NewCellEntity = FacTD_InitializerUtil::CreateGridCell(World, GridRootEntity, CurrentCellCoordinate);
                GridComp.GridEntities[CurrentCellCoordinate] = EntityUtil::ToInt32(NewCellEntity);
            }
        }
    }

    // Remove building components from the original cell
    World.Remove<FFacTD_BuildingComponent>(CellEntity);
    World.Remove<FFacTD_DirectionComponent>(CellEntity);
    World.Remove<FFacTD_DirectionDirtyTag>(CellEntity);

    // Reset the original cell to a normal grid cell
    World.Emplace<FFacTD_GridCellComponent>(CellEntity, FFacTD_GridCellComponent {
        .GridPosition = GridPosition,
        .OccupantEntity = EntityUtil::ToInt32(entt::null),
    });

    // You might want to add additional cleanup here, such as destroying any associated actors

    UE_LOG(LogTemp, Warning, TEXT("Building destroyed at position %s"), *GridPosition.ToString());
}


void AFacTD_PlayerController::TryRotate(const FIntVector& GridPosition)
{
	FEntityWorld& World = EntityUtil::GetEntityWorld(this);

	EEntity GridRootEntity = EntityUtil::GetSingletonEntity<FFacTD_GridComponent>(World);
	auto& GridComp = World.Get<FFacTD_GridComponent>(GridRootEntity);

	if (!GridComp.GridEntities.Contains(GridPosition))
	{
		UE_LOG(LogTemp, Warning, TEXT("No grid cell at position %s"), *GridPosition.ToString());
		return;
	}

	EEntity CellEntity = EntityUtil::ToEntity(GridComp.GridEntities[GridPosition]);
	auto& CellComp = World.Get<FFacTD_GridCellComponent>(CellEntity);

	EEntity OccupantEntity = EntityUtil::ToEntity(CellComp.OccupantEntity);
	if (!World.Valid(OccupantEntity))
	{
		UE_LOG(LogTemp, Warning, TEXT("No building at position %s"), *GridPosition.ToString());
		return;
	}

	auto& DirectionComponent = World.Get<FFacTD_DirectionComponent>(OccupantEntity);
	EFacTD_BuildingDirection NewDirection = static_cast<EFacTD_BuildingDirection>((static_cast<int32>(DirectionComponent.Direction) + 1) % 4);
	DirectionComponent.Direction = NewDirection;
	World.Emplace<FFacTD_DirectionDirtyTag>(OccupantEntity);
}

void AFacTD_PlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	const UWorld* World = GetWorld();

	// Start = Camera
	const FVector Start = PlayerCameraManager->GetCameraLocation() + PlayerCameraManager->GetActorForwardVector() * 50.0f;
	const FVector End = Start + PlayerCameraManager->GetActorForwardVector() * 10000.0f;
	FHitResult HitResult;
	
	if (World->LineTraceSingleByChannel(HitResult, Start, End, TERRAIN_TRACE_CHANNEL))
	{
		DrawDebugString(World, HitResult.ImpactPoint, FString::Printf(TEXT("X: %lld, Y: %lld"),
			FMath::RoundToInt(HitResult.ImpactPoint.X / 100),
			FMath::RoundToInt(HitResult.ImpactPoint.Y / 100)), nullptr, FColor::Red, World->GetDeltaSeconds(), false, 1.f);

		CurrentGridPosition = FIntVector(FMath::RoundToInt(HitResult.ImpactPoint.X / 100), FMath::RoundToInt(HitResult.ImpactPoint.Y / 100), 0);
	}
}
