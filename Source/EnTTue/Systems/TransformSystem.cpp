// Fill out your copyright notice in the Description page of Project Settings.

#include "EnTTue/Systems/TransformSystem.h"

#include "EnTTue/Components/Tags.h"
#include "EnTTue/Components/TransformComponents.h"
#include "EnTTue/Utils/TransformUtil.h"
#include "EnTTue/Utils/EntityUtil.h"

void HandleLastTransform(FEntityWorld& World) {
	
	// Handle LastPosition
	for (auto&& [Entity, Position, LastPosition] : World.ForEach<FPositionComponent, FLastPositionComponent>(entt::exclude<FStaticTag, FTransformDirtyTag>)) {
		if (Position.Equals(LastPosition)) {
			continue;
		}
		
		EntityUtil::ForEachRelative(World, Entity, true, [&](const EEntity RelativeEntity) {
			World.Emplace<FTransformDirtyTag>(RelativeEntity);
			World.Remove<FWorldPositionComponent>(RelativeEntity); // Calculated World Result is now Invalid.
		});

		World.Patch<FLastPositionComponent>(Entity, [&](FLastPositionComponent& Component) {
			Component = Position;
		});
	}

	// Handle LastRotation
	for (auto&& [Entity, Rotation, LastRotation] : World.ForEach<FRotationComponent, FLastRotationComponent>(entt::exclude<FStaticTag, FTransformDirtyTag>)) {
		if (Rotation.Equals(LastRotation)) {
			continue;
		}

		EntityUtil::ForEachRelative(World, Entity, true, [&](const EEntity RelativeEntity) {
			World.Emplace<FTransformDirtyTag>(RelativeEntity);
			World.Remove<FWorldRotationComponent>(RelativeEntity); // Calculated World Result is now Invalid.
		});
		
		World.Patch<FLastRotationComponent>(Entity, [&](FLastRotationComponent& Component) {
			Component = Rotation;
		});
	}

	// Handle LastScale
	for (auto&& [Entity, Scale, LastScale] : World.ForEach<FScaleComponent, FLastScaleComponent>(entt::exclude<FStaticTag, FTransformDirtyTag>)) {
		if (Scale.Equals(LastScale)) {
			continue;
		}
		
		EntityUtil::ForEachRelative(World, Entity, true, [&](const EEntity RelativeEntity) {
			World.Emplace<FTransformDirtyTag>(RelativeEntity);
			World.Remove<FWorldScaleComponent>(RelativeEntity); // Calculated World Result is now Invalid.
		});
		
		World.Patch<FLastScaleComponent>(Entity, [&](FLastScaleComponent& Component) {
			Component = Scale;
		});
	}

	for (auto&& [Entity, ChunkComp] : World.ForEach<FChunkComponent, FChunkInitializedTag, FTransformDirtyTag>()) {
		World.Erase<FChunkInitializedTag>(Entity);
	}
}

void HandleVelocities(const float DeltaTime, FRegistry& Reg) {
	// Handle Velocity & Friction
	Reg.view<FPositionComponent, FVelocityComponent>().
		each([&](const EEntity Entity, const FPositionComponent& Position, const FVelocityComponent& Velocity) {
			if (!Velocity.Delta.Equals(FVector::ZeroVector)) {
				Reg.patch<FPositionComponent>(Entity, [&](FPositionComponent& Component) {
					Component += Velocity.Delta * DeltaTime;
				});

				if (FMath::IsNearlyEqual(Velocity.Friction, 0.f)) {
					return;
				}

				Reg.patch<FVelocityComponent>(Entity, [&](FVelocityComponent& Component) {
					Component.Delta = FMath::Lerp(Velocity.Delta, FVector::ZeroVector, Velocity.Friction * DeltaTime);
				});
			}
		});

	// Handle AngularVelocity & Friction
	Reg.view<FRotationComponent, FAngularVelocityComponent>().
		each([&](const EEntity Entity, const FRotationComponent& Rotation, const FAngularVelocityComponent& AngularVelocity) {
			if (!AngularVelocity.Delta.Equals(FRotator::ZeroRotator)) {
				Reg.patch<FRotationComponent>(Entity, [&](FRotationComponent& Component) {
					Component += AngularVelocity.Delta * DeltaTime;
				});

				if (FMath::IsNearlyEqual(AngularVelocity.Friction, 0.f)) {
					return;
				}

				Reg.patch<FAngularVelocityComponent>(Entity, [&](FAngularVelocityComponent& Component) {
					Component.Delta = FMath::Lerp(AngularVelocity.Delta, FRotator::ZeroRotator, AngularVelocity.Friction * DeltaTime);
				});
			}
		});
}

void UTransformSystem::Tick(AActor* ActorRoot, FEntityWorld& World, const float DeltaTime) {
	FRegistry& Reg = World.Registry;

	TickIndex++;
	
	HandleVelocities(DeltaTime, Reg);

	// Handle Velocity Acceleration
	Reg.view<FVelocityAcceleratorComponent, FVelocityComponent>().
	each([&](const EEntity Entity, const FVelocityAcceleratorComponent& VelocityAccelerator, const FVelocityComponent& Velocity) {
		Reg.patch<FVelocityComponent>(Entity, [&](FVelocityComponent& Component) {
			Component.Delta = VelocityAccelerator.Acceleration;
		});
	});

	Reg.view<FPositionComponent, FVelocityComponent, FMoveToTargetComponent>().
	each([&](const EEntity Entity, const FPositionComponent& Position, const FVelocityComponent& Velocity, const FMoveToTargetComponent& MoveToTarget) {
		if (!World.Valid(MoveToTarget.Target)) {
			World.EmplaceOrReplace<FDestroyAtEndOfTickTag>(Entity);
			return;
		}

		const float MovementSpeedAcceleration = 50.f;
		const float MovementSpeed = 1000.f;

		const FVector Direction = (Reg.get<FPositionComponent>(MoveToTarget.Target) - Position);
		World.Patch<FMoveToTargetComponent>(Entity, [&](FMoveToTargetComponent& Component) {
			Component.Distance = Direction.Length(); // TODO: Should be Squared
		});

		const bool CompleteTag = Reg.all_of<FMoveToTargetCompleteTag>(Entity);
		if (MoveToTarget.Distance <= MoveToTarget.DistanceTillStop) {
			World.Patch<FVelocityComponent>(Entity, [&](FVelocityComponent& Component) {
				Component.Delta = FMath::Lerp(Velocity.Delta, FVector::ZeroVector, MovementSpeedAcceleration * DeltaTime);
			});
			if (!CompleteTag) {
				World.Emplace<FMoveToTargetCompleteTag>(Entity);
			}
		} else {
			World.Patch<FVelocityComponent>(Entity, [&](FVelocityComponent& Component) {
				Component.Delta = FMath::Lerp(Velocity.Delta, Direction.GetSafeNormal() * MovementSpeed, MovementSpeedAcceleration * DeltaTime);
			});
			if (CompleteTag) {
				World.Emplace<FMoveToTargetCompleteTag>(Entity);
			}
		}
	});

	for (auto&& [Entity, Chunk] : World.ForEach<FChunkComponent>(entt::exclude<FChunkInitializedTag>)) {
		FVector WorldPosition = World.GetWorldPosition(Entity);

		World.Patch<FChunkComponent>(Entity, [&](FChunkComponent& Component) {
			Component.RelevantCell = FIntVector(
				FMath::FloorToInt(WorldPosition.X / Chunk.ChunkSize),
				FMath::FloorToInt(WorldPosition.Y / Chunk.ChunkSize),
				0
			);

			Component.NeighbourCells.Empty();

			size_t Index = 0;
			for (int32 x = -1; x <= 1; ++x) {
				for (int32 y = -1; y <= 1; ++y) {
					if (x == 0 && y == 0) continue; // Skip the center cell
					Component.NeighbourCells.EmplaceAt(Index++, Component.RelevantCell + FIntVector(x, y, 0));
				}
			}
		});

		World.Emplace<FChunkInitializedTag>(Entity);
	}

	for (auto&& [Entity, Chunk] : World.ForEach<FChunkComponent, FAntiBoidTag>(entt::exclude<FWasRecentlyKnockedBackTag>)) {
		FVector Position = World.GetWorldPosition(Entity);
		
		for (auto&& [OtherEntity, OtherChunk] : World.ForEach<FChunkComponent, FAntiBoidTag>()) {
			if (Entity == OtherEntity) {
				continue;
			}

			if (Chunk.RelevantCell != OtherChunk.RelevantCell && !Chunk.NeighbourCells.Contains(OtherChunk.RelevantCell)) {
				continue;
			}

			FVector OtherPosition = World.GetWorldPosition(OtherEntity);
			const FVector DirN = -(OtherPosition - Position).GetSafeNormal2D();
			TransformUtil::HandleKnockBack(Reg, Entity, 0.5f, 100.f, DirN, false);
		}
	}

	// Handle KnockBacks
	Reg.view<FPositionComponent, FKnockBackComponent>().each([&](const EEntity Entity, const FPositionComponent& Position, const FKnockBackComponent& KnockBack) {
		Reg.patch<FKnockBackComponent>(Entity, [&](FKnockBackComponent& Component) {
			Component.KnockBackTimer -= DeltaTime;
		});

		const float Intensity = KnockBack.KnockBackTimer * 10.f;

		Reg.patch<FPositionComponent>(Entity, [&](FPositionComponent& Component) {
			Component += KnockBack.KnockBackDirection * KnockBack.KnockBackPower * Intensity * DeltaTime;
		});	

		if (KnockBack.KnockBackTimer <= 0.f) {
			Reg.erase<FKnockBackComponent>(Entity);
		}
	});

	Reg.view<FLookAtVelocityTag, FPositionComponent, FRotationComponent, FVelocityComponent>().
	each([&](const EEntity Entity, const FPositionComponent& Position, const FRotationComponent& Rotation, const FVelocityComponent& Velocity) {
		if (!Velocity.Delta.IsNearlyZero()) {
			const FRotator NewRotation = UKismetMathLibrary::FindLookAtRotation(Position, Position + Velocity.Delta);
			World.Patch<FRotationComponent>(Entity, [&](FRotationComponent& Component) {
				Component = NewRotation;
			});

			// DrawDebugLine(ActorRoot->GetWorld(), Position, Position + (Velocity.Delta * 10.f), FColor::Red, false);
		}

	});

	HandleLastTransform(World);
	
}
