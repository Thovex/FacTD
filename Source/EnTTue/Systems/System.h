// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnTTue/EntityWorld.h"

#include "System.generated.h"

UCLASS(Blueprintable, BlueprintType)
class ENTTUE_API USystem : public UObject {
	GENERATED_BODY()

public:
	virtual void Init(AActor* ActorRoot, FEntityWorld& World) {}
	virtual void Tick(AActor* ActorRoot, FEntityWorld& World, float DeltaTime) {}
};
