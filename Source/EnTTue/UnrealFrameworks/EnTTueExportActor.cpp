// Fill out your copyright notice in the Description page of Project Settings.


#include <EnTTue/UnrealFrameworks/EnTTueExportActor.h>

AEnTTueExportActor::AEnTTueExportActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AEnTTueExportActor::BeginPlay()
{
	Super::BeginPlay();
}

void AEnTTueExportActor::Export(int32 CreatedEntity)
{

	Export_Implementation(CreatedEntity);

	this->Destroy();
}
