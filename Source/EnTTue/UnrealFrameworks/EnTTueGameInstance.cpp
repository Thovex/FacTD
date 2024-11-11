// Fill out your copyright notice in the Description page of Project Settings.

#include "EnTTue/UnrealFrameworks/EnTTueGameInstance.h"

#include <EnTTue/Utils/EntityBuilderUtil.h>

#include "EnTTinspector/Inspectors/ComponentInspector.h"
#include "EnTTinspector/Macros.h"

DEFINE_LOG_CATEGORY(LogECS);

UEnTTueGameInstance::UEnTTueGameInstance(): SystemRunner(nullptr) {
	World = FEntityWorld();
	World.RootEntity = EntityBuilderUtil::CreateEntity(World, FName("Root"), FTransform::Identity);
}

TArray<int32> UEnTTueGameInstance::GetEntities() const {
	TArray<int32> Entities;

	for (auto&& [Entity] : World.Registry.storage<EEntity>()->each()) {
		Entities.Add(static_cast<int32>(Entity));
	}

	return Entities;
}

void UEnTTueGameInstance::RegisterInspectors(TMap<FName, TFunction<TSharedRef<IComponentInspector>(FEntityWorld&, EEntity Entity)>>& RegisteredInspectors) {
}

FEntityWorld& UEnTTueGameInstance::GetEntityWorld() {
	return World;
}
