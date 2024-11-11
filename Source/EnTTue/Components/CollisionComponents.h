#pragma once

#include "EnTTue/Include.h"

#include "CollisionComponents.generated.h"

USTRUCT(BlueprintType)
struct FCollisionShapeComponent
{
	GENERATED_BODY()

	// Read-Only
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) AEnTTueCollision* CollisionActor = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FName CollisionProfile = FName(NAME_None);
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector Offset = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool DestroyOnCollision = false;

	FCollisionShapeComponent() {}
	explicit FCollisionShapeComponent(const EEntity CallbackEntity, const FName CollisionProfile, const bool DestroyOnCollision, const FVector Offset = FVector::ZeroVector): CollisionActor(nullptr) {
		this->CallbackEntity = CallbackEntity;
		this->CollisionProfile = CollisionProfile;
		this->Offset = Offset;
		this->DestroyOnCollision = DestroyOnCollision;
	}

	EEntity CallbackEntity = entt::null;
};

struct FPhysicsComponent {
	
};

USTRUCT(BlueprintType)
struct FBoxCollisionComponent // APPLY_ENTTUE_REFLECTION()
	: public FCollisionShapeComponent {

	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector Extents = FVector::ZeroVector;

	FBoxCollisionComponent() {}
	explicit FBoxCollisionComponent(const EEntity CallbackEntity, const FName CollisionProfile, const bool DestroyOnCollision, const FVector Extents, const FVector Offset = FVector::ZeroVector) :
	FCollisionShapeComponent(CallbackEntity, CollisionProfile, DestroyOnCollision, Offset) {
		this->Extents = Extents;
	}
};

USTRUCT(BlueprintType)
struct FSphereCollisionComponent // APPLY_ENTTUE_REFLECTION()
	: public FCollisionShapeComponent {
	
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Radius = 0.f;

	FSphereCollisionComponent() {}
	explicit FSphereCollisionComponent(const EEntity CallbackEntity, const FName CollisionProfile, const bool DestroyOnCollision, const float Radius, const FVector Offset = FVector::ZeroVector) :
	FCollisionShapeComponent(CallbackEntity, CollisionProfile, DestroyOnCollision, Offset) {
		this->Radius = Radius;
	}
};

// Only lives the one frame after it is emplaced.
struct FCollisionComponent
{ // Maybe called "Event" or "Command"?
	EEntity ColliderEntity;
	EEntity OtherEntity;

	FVector ImpactPoint;
	FVector ImpactNormal;

	bool Destroy = false;
	
	explicit FCollisionComponent(const EEntity ColliderEntity, const EEntity OtherEntity, const FVector ImpactPoint, const FVector ImpactNormal) {
		this->ColliderEntity = ColliderEntity;
		this->OtherEntity = OtherEntity;
		this->ImpactPoint = ImpactPoint;
		this->ImpactNormal = ImpactNormal;
	}
};
