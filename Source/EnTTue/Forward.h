#pragma once

class ASystemRunner;
class UWorld;

class AEnTTueCollision;
class AEnTTueBoxCollision;
class AEnTTueSphereCollision;

class UShapeComponent;
class UBoxComponent;
class USphereComponent;

class AEnTTueNiagara;
class UNiagaraComponent;

class UEnTTueAnimationInstance;
class UEcsNiagara;

class UEnTTueGameInterface;

// EnTTue/BaseComponents
struct FNameComponent;
struct FParentComponent;
struct FChildrenComponent;
struct FLifeTimeComponent;

// EnTTue/CollisionComponents
struct FCollisionShapeComponent;
struct FPhysicsComponent;
struct FBoxCollisionComponent;
struct FSphereCollisionComponent;
struct FCollisionComponent;

// EnTTue/Events
struct FGenericEvent;
struct FDamageNumberEvent;
struct FEventComponent;

// EnTTue/RenderingComponents
struct FHismMeshComponent;
struct FSkMeshComponent;
struct FNiagaraComponent;
struct FFresnelFlashComponent;

// EnTTue/TransformComponents
struct FWorldPositionComponent;
struct FWorldRotationComponent;
struct FWorldScaleComponent;
struct FPositionComponent;
struct FLastPositionComponent;
struct FRotationComponent;
struct FLastRotationComponent;
struct FScaleComponent;
struct FLastScaleComponent;
struct FVelocityComponent;
struct FVelocityAcceleratorComponent;
struct FAngularVelocityComponent;
struct FMoveToTargetComponent;
struct FMoveToTargetCompleteTag;
struct FKnockBackComponent;
struct FWasRecentlyKnockedBackTag;
struct FChunkInitializedTag;
struct FAntiBoidTag;
struct FPingPongScaleUniformComponent;

