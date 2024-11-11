// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnTTue/Include.h"

#include "TransformSystem.generated.h"

UCLASS(Blueprintable, BlueprintType)
class ENTTUE_API UTransformSystem : public USystem {
	GENERATED_BODY()

protected:
	virtual void Tick(AActor* ActorRoot, FEntityWorld& World, const float DeltaTime) override;

private:
	uint64 TickIndex = 0;
};
