// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <EnTTue/UnrealFrameworks/EnTTueGameInstance.h>
#include "FacTD_GameInstance.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ENTTUE_PROJECT_API UFacTD_GameInstance : public UEnTTueGameInstance
{
	GENERATED_BODY()

protected:
	virtual void RegisterInspectors(TMap<FName, TFunction<TSharedRef<IComponentInspector>(FEntityWorld&, EEntity Entity)>>& RegisteredInspectors) override;
};
