// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnTTue/Include.h"

#include "EnTTue/UnrealFrameworks/Collision/EnTTueCollision.h"

#include "EnTTueSphereCollision.generated.h"

class USphereComponent;

UCLASS(BlueprintType)
class ENTTUE_API AEnTTueSphereCollision : public AEnTTueCollision {
	GENERATED_BODY()

public:
	AEnTTueSphereCollision();

	virtual UShapeComponent* GetShape() override;

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USphereComponent* SphereCollision;

};
