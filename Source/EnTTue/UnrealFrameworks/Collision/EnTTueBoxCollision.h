// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnTTue/Include.h"

#include "EnTTue/UnrealFrameworks/Collision/EnTTueCollision.h"

#include "EnTTueBoxCollision.generated.h"

UCLASS(BlueprintType)
class ENTTUE_API AEnTTueBoxCollision : public AEnTTueCollision {
	GENERATED_BODY()

public:
	AEnTTueBoxCollision();

	virtual UShapeComponent* GetShape() override;

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* BoxCollision;
	
};
