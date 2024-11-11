// Fill out your copyright notice in the Description page of Project Settings.


#include <EnTTue_Project/GameModules/FacTD/Utils/FacTD_BuildingUtil.h>

namespace FacTD_BuildingUtil
{
	FVector ConvertBuildingDirection(const EFacTD_BuildingDirection& Direction)
	{
		switch (Direction) {
		case EFacTD_BuildingDirection::EFacTD_BuildingDirection_Up:
			{
				return FVector::ForwardVector;
			}
		case EFacTD_BuildingDirection::EFacTD_BuildingDirection_Right:
			{
				return FVector::RightVector;
			}
		case EFacTD_BuildingDirection::EFacTD_BuildingDirection_Down:
			{
				return FVector::BackwardVector;
			}
		case EFacTD_BuildingDirection::EFacTD_BuildingDirection_Left:
			{
				return FVector::LeftVector;
			}
		}
		return FVector::ZeroVector;
	}
}

FVector UFacTD_BuildingUtil::ConvertBuildingDirection(const EFacTD_BuildingDirection& Direction)
{
	return FacTD_BuildingUtil::ConvertBuildingDirection(Direction);
}
