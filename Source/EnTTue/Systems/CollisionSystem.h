// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnTTue/Include.h"

#include "CollisionSystem.generated.h"

UCLASS(Blueprintable, BlueprintType)
class ENTTUE_API UCollisionSystem : public USystem {
	GENERATED_BODY()

protected:
	virtual void Tick(AActor* ActorRoot, FEntityWorld& World, const float DeltaTime) override;

private:
	void SetupCollisions(const AActor* ActorRoot, FEntityWorld& World, FRegistry& Reg) const;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AEnTTueCollision> BoxCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AEnTTueCollision> SphereCollision;
};
