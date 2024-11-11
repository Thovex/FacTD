// Fill out your copyright notice in the Description page of Project Settings.

#include "EnTTue/UnrealFrameworks/Widget/EnTTueDebugPanel.h"

void UEnTTueDebugPanel::NativeConstruct() {
	Super::NativeConstruct();
	
	UEnTTueGameInstance* GameInst = static_cast<UEnTTueGameInstance*>(GetGameInstance());
	World = &GameInst->GetEntityWorld();
}

void UEnTTueDebugPanel::NativeTick(const FGeometry& MyGeometry, float InDeltaTime) {
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (!World) {
		return;
	}

	AliveEntityCount = World->Registry.storage<EEntity>().in_use();
	TotalEntityCount = World->Registry.storage<EEntity>().size();
}
