// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnTTue/Include.h"

#include "GameFramework/Actor.h"

#include "EnTTueCollision.generated.h"

UCLASS(BlueprintType)
class ENTTUE_API AEnTTueCollision : public AActor {
	GENERATED_BODY()

public:
	AEnTTueCollision();
	
	FEntityWorld* World;
	EEntity CollisionOwner;
	EEntity CallbackEntity;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);

	TArray<EEntity> OverlappingEntities;

	virtual UShapeComponent* GetShape() { return nullptr; }
};
