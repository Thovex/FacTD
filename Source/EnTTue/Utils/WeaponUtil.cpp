#include "EnTTue/Utils/WeaponUtil.h"

#include <EnTTue/Components/TransformComponents.h>
#include <EnTTue/Utils/EntityUtil.h>
#include <EnTTue/Components/CollisionComponents.h>

void UWeaponLibrary::CreateArtificialEnemyCollision(const UObject* WorldContextObject, int32 EntityId) {
	FRegistry& Reg = EntityUtil::GetEntityWorld(WorldContextObject).Registry;

	const EEntity Entity = static_cast<EEntity>(EntityId);

	if (!Reg.valid(Entity)) {
		UE_LOG(LogECS, Error, TEXT("Invalid Entity in CreateArtificialEnemyCollision"));
		return;
	}
	
	const FMoveToTargetComponent* WalkToTarget = Reg.try_get<FMoveToTargetComponent>(Entity);
	if (!WalkToTarget) {
		UE_LOG(LogECS, Error, TEXT("Entity calling CreateArtificialEnemyCollision has no WalkToTarget"));
		return;
	}

	const EEntity OtherEntity = static_cast<EEntity>(EntityId);
	if (!Reg.valid(OtherEntity)) {
		UE_LOG(LogECS, Error, TEXT("Invalid Other Entity in CreateArtificialEnemyCollision"));
		return;
	}
	
	const FPositionComponent& Position = Reg.get<FPositionComponent>(Entity);
	const FPositionComponent& TargetPosition = Reg.get<FPositionComponent>(OtherEntity);

	Reg.emplace<FCollisionComponent>(Reg.create(), FCollisionComponent(Entity, WalkToTarget->Target,
		Position, (TargetPosition-Position).GetSafeNormal2D()));
}
