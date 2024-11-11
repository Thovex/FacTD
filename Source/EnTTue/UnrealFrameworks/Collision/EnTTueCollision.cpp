// Fill out your copyright notice in the Description page of Project Settings.

#include "EnTTue/UnrealFrameworks/Collision/EnTTueCollision.h"
#include "EnTTue/Components/CollisionComponents.h"

#include "Components/PrimitiveComponent.h"

AEnTTueCollision::AEnTTueCollision(): World(nullptr), CollisionOwner(), CallbackEntity() {
	PrimaryActorTick.bCanEverTick = false;
}


void AEnTTueCollision::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	//UE_LOG(LogECS, Display, TEXT("Overlap occurred!"));

	if (!World) {
		UE_LOG(LogECS, Error, TEXT("ECS Collision does not have World! Make sure it is a Deferred Spawn!"));
		return;
	}
	
	if (!IsValid(OtherActor)) {
		return;
	}
	
	if (!OtherActor->IsA<AEnTTueCollision>()) {
		return;
	}
	
	const FVector ImpactPoint = OverlappedComponent->GetComponentLocation();
	const FVector ImpactNormal = (OtherComponent->GetComponentLocation() - ImpactPoint).GetSafeNormal();

	const AEnTTueCollision* OtherCollision = static_cast<AEnTTueCollision*>(OtherActor);
	OverlappingEntities.Add(OtherCollision->CollisionOwner);

	if (World->Registry.valid(CollisionOwner) && World->Registry.valid(OtherCollision->CollisionOwner)) {
		World->Registry.emplace_or_replace<FCollisionComponent>(World->Registry.create(),
			FCollisionComponent(CollisionOwner, OtherCollision->CollisionOwner, ImpactPoint, ImpactNormal));
	}
}


void AEnTTueCollision::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex) {
	if (!World) {
		UE_LOG(LogECS, Error, TEXT("ECS Collision does not have World! Make sure it is a Deferred Spawn!"));
		return;
	}
	
	if (!IsValid(OtherActor)) {
		return;
	}
	
	if (!OtherActor->IsA<AEnTTueCollision>()) {
		return;
	}
	
	const AEnTTueCollision* OtherCollision = static_cast<AEnTTueCollision*>(OtherActor);
	OverlappingEntities.Remove(OtherCollision->CollisionOwner);
}
