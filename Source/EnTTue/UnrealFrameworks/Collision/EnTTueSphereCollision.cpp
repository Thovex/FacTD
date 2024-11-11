// Fill out your copyright notice in the Description page of Project Settings.

#include "EnTTueSphereCollision.h"

#include "Components/SphereComponent.h"

AEnTTueSphereCollision::AEnTTueSphereCollision() {
	PrimaryActorTick.bCanEverTick = false;

	SphereCollision = CreateDefaultSubobject<USphereComponent>("SphereCollision");
	SphereCollision->SetSphereRadius(1.f);
	RootComponent = SphereCollision;

	SphereCollision->SetVisibility(true);
	SphereCollision->SetHiddenInGame(true);
	
	SphereCollision->SetGenerateOverlapEvents(true);
}

UShapeComponent* AEnTTueSphereCollision::GetShape() {
	return SphereCollision;
}

void AEnTTueSphereCollision::BeginPlay() {
	Super::BeginPlay();
	
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AEnTTueCollision::OnOverlapBegin);
	SphereCollision->OnComponentEndOverlap.AddDynamic(this, &AEnTTueCollision::OnOverlapEnd);
}
