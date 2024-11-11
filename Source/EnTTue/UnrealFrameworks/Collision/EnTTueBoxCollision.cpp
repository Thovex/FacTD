// Fill out your copyright notice in the Description page of Project Settings.


#include "EnTTueBoxCollision.h"

#include "Components/BoxComponent.h"

AEnTTueBoxCollision::AEnTTueBoxCollision() {
	PrimaryActorTick.bCanEverTick = false;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	BoxCollision->SetBoxExtent(FVector::OneVector);
	RootComponent = BoxCollision;

	BoxCollision->SetVisibility(true);
	BoxCollision->SetHiddenInGame(true);
	
	BoxCollision->SetGenerateOverlapEvents(true);
}
UShapeComponent* AEnTTueBoxCollision::GetShape() {
	return BoxCollision;
}

void AEnTTueBoxCollision::BeginPlay() {
	Super::BeginPlay();
	
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AEnTTueCollision::OnOverlapBegin);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &AEnTTueCollision::OnOverlapEnd);
}
