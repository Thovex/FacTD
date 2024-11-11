// Fill out your copyright notice in the Description page of Project Settings.


#include <EnTTue_Project/GameModules/FacTD/FacTD_GameInstance.h>
#include <EnTTue_Project/GameModules/FacTD/Components/FacTD_GridComponents.h>
#include <EnTTue_Project/GameModules/FacTD/Inspectors/FacTD_Inspectors.h>

void UFacTD_GameInstance::RegisterInspectors(TMap<FName, TFunction<TSharedRef<IComponentInspector>(FEntityWorld&, EEntity Entity)>>& RegisteredInspectors)
{
	Super::RegisterInspectors(RegisteredInspectors);

	REGISTER_INSPECTOR(FFacTD_GridComponent, Inspectors::FacTD::FFacTD_GridComponentInspector);
}
