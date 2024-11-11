#include "EnTTue/Utils/TransformUtil.h"
#include "EnTTue/Utils/EntityUtil.h"
#include "EnTTue/Components/TransformComponents.h"

void UTransformLibrary::Set_NameComponent(const UObject* WorldContextObject, const int32 EntityId, const FNameComponent& NameComponent) {
	FEntityWorld& World = EntityUtil::GetEntityWorld(WorldContextObject);

	if (World.AllOf<FNameComponent>(EntityUtil::ToEntity(EntityId))) {
		World.Registry.patch<FNameComponent>(static_cast<EEntity>(EntityId), [&NameComponent](FNameComponent& Component) {
			Component.Name = NameComponent.Name;
		});
	} else {
		World.Emplace<FNameComponent>(static_cast<EEntity>(EntityId), NameComponent);
	}
}

void UTransformLibrary::Set_PositionComponent(const UObject* WorldContextObject, const int32 EntityId, const FPositionComponent& PositionComponent) {
	FEntityWorld& World = EntityUtil::GetEntityWorld(WorldContextObject);

	if (World.AllOf<FPositionComponent>(EntityUtil::ToEntity(EntityId))) {
		World.Registry.patch<FPositionComponent>(static_cast<EEntity>(EntityId), [&PositionComponent](FPositionComponent& Component) {
			Component = PositionComponent;
		});
	} else {
		 World.Emplace<FPositionComponent>(static_cast<EEntity>(EntityId), PositionComponent);
	 }
}

void UTransformLibrary::Get_PositionComponent(const UObject* WorldContextObject, const int32 EntityId, FPositionComponent& PositionComponent) {
	PositionComponent = EntityUtil::GetEntityWorld(WorldContextObject).Registry.get<FPositionComponent>(static_cast<EEntity>(EntityId));
}

void UTransformLibrary::Get_RotationComponent(const UObject* WorldContextObject, const int32 EntityId, FRotationComponent& RotationComponent) {
	RotationComponent = EntityUtil::GetEntityWorld(WorldContextObject).Registry.get<FRotationComponent>(static_cast<EEntity>(EntityId));
}

void UTransformLibrary::Set_VelocityComponent(const UObject* WorldContextObject, const int32 EntityId, const FVelocityComponent& VelocityComponent) {
	FEntityWorld& World = EntityUtil::GetEntityWorld(WorldContextObject);

	if (World.AllOf<FVelocityComponent>(EntityUtil::ToEntity(EntityId))) {
		World.Registry.patch<FVelocityComponent>(static_cast<EEntity>(EntityId), [&VelocityComponent](FVelocityComponent& Component) {
			Component = VelocityComponent;
		});
	} else {
		World.Emplace<FVelocityComponent>(static_cast<EEntity>(EntityId), VelocityComponent);
	}
}
void UTransformLibrary::Get_VelocityComponent(const UObject* WorldContextObject, const int32 EntityId, FVelocityComponent& VelocityComponent) {
	VelocityComponent = EntityUtil::GetEntityWorld(WorldContextObject).Registry.get<FVelocityComponent>(static_cast<EEntity>(EntityId));
}


namespace TransformUtil {
	FTransform TransformUtil::GetTransform(FRegistry& Reg, const EEntity Entity) {
		return FTransform(Reg.get<FRotationComponent>(Entity), Reg.get<FPositionComponent>(Entity), Reg.get<FScaleComponent>(Entity));
	}
	
	void TransformUtil::HandleKnockBack(FRegistry& Reg, const EEntity KnockBackEntity, const float KnockBackTimer, const float KnockBackPower, const FVector& KnockBackDirection, const bool Force) {

		if (!Force) {
			if (Reg.all_of<FWasRecentlyKnockedBackTag>(KnockBackEntity)) {
				return;
			}
		}
		
		if (FKnockBackComponent* KnockBackComponent = Reg.try_get<FKnockBackComponent>(KnockBackEntity)) {
			// Set if the curr duration is smaller than inc duration... 
			if (KnockBackComponent->KnockBackTimer < KnockBackTimer) {
				KnockBackComponent->KnockBackTimer = KnockBackTimer;
			}
			KnockBackComponent->KnockBackPower += KnockBackPower;

			// Normalize so the power doesn't go through the roof.
			KnockBackComponent->KnockBackDirection = (KnockBackComponent->KnockBackDirection + KnockBackDirection).GetSafeNormal();
		} else {
			Reg.emplace<FKnockBackComponent>(KnockBackEntity,
				FKnockBackComponent(KnockBackTimer, KnockBackPower, KnockBackDirection)); // Ignore Z	
		}

		Reg.emplace<FWasRecentlyKnockedBackTag>(KnockBackEntity);
	}
}