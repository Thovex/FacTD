// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnTTue/Include.h"

#include "GameFramework/Actor.h"

#include "EnTTueNiagara.generated.h"

UCLASS(BlueprintType)
class ENTTUE_API AEnTTueNiagara : public AActor {
	GENERATED_BODY()

	AEnTTueNiagara();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* Transform;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UNiagaraComponent* NiagaraComponent;
};
