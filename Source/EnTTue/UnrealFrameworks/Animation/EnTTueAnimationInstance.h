// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnTTue/Include.h"

#include "Animation/AnimInstance.h"

#include "EnTTueAnimationInstance.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ENTTUE_API UEnTTueAnimationInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ShouldMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ShouldAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 OwnerEntityId;

	EEntity OwnerEntity = entt::null;
};
