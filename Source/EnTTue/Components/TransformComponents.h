#pragma once

#include "EnTTue/Include.h"

#include "TransformComponents.generated.h"

struct FWorldPositionComponent {
	FVector Position;
};

struct FWorldRotationComponent  {
	FRotator Rotation;
};

struct FWorldScaleComponent{
	FVector Scale;
};

USTRUCT(BlueprintType)
struct FPositionComponent // APPLY_ENTTUE_REFLECTION()
	: public FVector {
	GENERATED_BODY()
	
	FPositionComponent& operator=(const FVector& Equals) {
		X = Equals.X;
		Y = Equals.Y;
		Z = Equals.Z;
		return *this;
	}
};
DEFINE_COMPONENT(FPositionComponent);

USTRUCT(BlueprintType)
struct FLastPositionComponent : public FVector {
	GENERATED_BODY()
	
	FLastPositionComponent& operator=(const FVector& Equals) {
		X = Equals.X;
		Y = Equals.Y;
		Z = Equals.Z;
		return *this;
	}
};
DEFINE_COMPONENT(FLastPositionComponent);

USTRUCT(BlueprintType)
struct FRotationComponent // APPLY_ENTTUE_REFLECTION()
	: public FRotator {
	GENERATED_BODY()

	FRotationComponent& operator=(const FRotator& Equals) {
		Pitch = Equals.Pitch;
		Yaw = Equals.Yaw;
		Roll = Equals.Roll;
		return *this;
	}
};
DEFINE_COMPONENT(FRotationComponent);

USTRUCT(BlueprintType)
struct FLastRotationComponent : public FRotator{
	GENERATED_BODY()

	FLastRotationComponent& operator=(const FRotator& Equals) {
		Pitch = Equals.Pitch;
		Yaw = Equals.Yaw;
		Roll = Equals.Roll;
		return *this;
	}
};
DEFINE_COMPONENT(FLastRotationComponent);

USTRUCT(BlueprintType)
struct FScaleComponent // APPLY_ENTTUE_REFLECTION()
	: public FVector {
	GENERATED_BODY()
	
	FScaleComponent& operator=(const FVector& Equals) {
		X = Equals.X;
		Y = Equals.Y;
		Z = Equals.Z;
		return *this;
	}
};
DEFINE_COMPONENT(FScaleComponent);

USTRUCT(BlueprintType)
struct FLastScaleComponent : public FVector {
	GENERATED_BODY()

	FLastScaleComponent& operator=(const FVector& Equals) {
		X = Equals.X;
		Y = Equals.Y;
		Z = Equals.Z;
		return *this;
	}
};
DEFINE_COMPONENT(FLastScaleComponent);

USTRUCT(BlueprintType)
struct FVelocityComponent // APPLY_ENTTUE_REFLECTION()
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Delta = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Friction = 0.f;
};
DEFINE_COMPONENT(FVelocityComponent);

USTRUCT(BlueprintType)
struct FVelocityAcceleratorComponent // APPLY_ENTTUE_REFLECTION()
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Acceleration = FVector::ZeroVector;
};

struct FMoveToTargetComponent
{
	EEntity Target;
	
	float DistanceTillStop;
	float Distance = -1.f;
};


struct FMoveToTargetWhenInRangeComponent {
	EEntity Target;

	float Range = 1000.f;
	float Distance = -1.f;
};


struct FKnockBackComponent
{
	float KnockBackTimer;
	float KnockBackPower;
	FVector KnockBackDirection;

	explicit FKnockBackComponent(const float KnockBackTimer, const float KnockBackPower, const FVector KnockBackDirection) {
		this->KnockBackTimer = KnockBackTimer;
		this->KnockBackPower = KnockBackPower;
		this->KnockBackDirection = KnockBackDirection;
	}
};

struct FWasRecentlyKnockedBackTag
{
	float GraceTimer = 1.f;
};

struct FChunkInitializedTag {};

USTRUCT(BlueprintType)
struct FChunkComponent // APPLY_ENTTUE_REFLECTION()
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ChunkSize = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIntVector RelevantCell = FIntVector::ZeroValue;

	
	TArray<FIntVector, TFixedAllocator<8>> NeighbourCells;
};

USTRUCT(BlueprintType)
struct FAntiBoidTag // APPLY_ENTTUE_REFLECTION()
{
	GENERATED_BODY()
};

USTRUCT(BlueprintType)
struct FAngularVelocityComponent {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator Delta;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Friction;

	FAngularVelocityComponent() : Delta(FRotator::ZeroRotator), Friction(0.f) {}
	explicit FAngularVelocityComponent(const FRotator Delta, const float Friction = 0.f) {
		this->Delta = Delta;
		this->Friction = Friction;
	}
};

USTRUCT(BlueprintType)
struct FPingPongScaleUniformComponent {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector MinScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector MaxScale;

	FPingPongScaleUniformComponent() : MinScale(FVector::ZeroVector), MaxScale(FVector::OneVector) {}
	explicit FPingPongScaleUniformComponent(const FVector MinScale, const FVector MaxScale) {
		this->MinScale = MinScale;
		this->MaxScale = MaxScale;
	}

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool Direction = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Alpha = 0.f;
};
