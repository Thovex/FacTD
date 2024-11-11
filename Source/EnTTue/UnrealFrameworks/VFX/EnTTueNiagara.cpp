// Fill out your copyright notice in the Description page of Project Settings.

#include "EnTTueNiagara.h"

#include "NiagaraComponent.h"

AEnTTueNiagara::AEnTTueNiagara() {
	PrimaryActorTick.bCanEverTick = false;

	Transform = CreateDefaultSubobject<USceneComponent>("Transform");
	RootComponent = Transform;

	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>("NiagaraComponent");
	NiagaraComponent->SetupAttachment(RootComponent);
}
