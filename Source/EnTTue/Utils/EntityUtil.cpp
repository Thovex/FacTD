#include "EnTTue/Utils/EntityUtil.h"

namespace EntityUtil {
	EEntity ToEntity(uint32 Id) {
		return static_cast<EEntity>(Id);
	}

	EEntity ToEntity(int32 Id) {
		return static_cast<EEntity>(Id);
	}

	uint32 ToUint32(EEntity Entity) {
		return static_cast<uint32>(Entity);
	}

	int32 ToInt32(EEntity Entity) {
		return static_cast<int32>(Entity);
	}

	FEntityWorld& GetEntityWorld(const UObject* WorldContextObject) {
		check(WorldContextObject);

		const UWorld* World = WorldContextObject->GetWorld();
		check(World);

		UGameInstance* GameInstance = World->GetGameInstance();
		check(GameInstance);

		UEnTTueGameInstance* EnTTGameInstance = static_cast<UEnTTueGameInstance*>(GameInstance);
		check(EnTTGameInstance);

		return EnTTGameInstance->World;
	}

	void AddSingletonEntity(FEntityWorld& World, const FName Name, const EEntity Entity)
	{
		if (World.SingletonEntities.Contains(Name)) {
			UE_LOG(LogECS, Error, TEXT("Trying to Recreate singleton: %s"), *Name.ToString());
		} else {
			World.SingletonEntities.Add(Name, Entity);
		}
	}

	bool GetSingletonEntity(FEntityWorld& World, const FName Name, EEntity& Entity) {
		if (World.SingletonEntities.Contains(Name)) { 
			Entity = World.SingletonEntities[Name];
			return true;
		}
		
		UE_LOG(LogECS, Error, TEXT("Trying to get uncreated singleton: %s"), *Name.ToString());
		
		Entity = entt::null;
		return false;
	}

	
}

bool UEntityLibrary::GetSingletonByName(const UObject* WorldContextObject, const FName& Name, int32& OutEntity)
{
	FEntityWorld& World = EntityUtil::GetEntityWorld(WorldContextObject);

	if (World.SingletonEntities.Contains(Name)) {
		OutEntity = EntityUtil::ToInt32(World.SingletonEntities[Name]);
		return true;
	}
	return false;
}

bool UEntityLibrary::IsValidEntity(const UObject* WorldContextObject, const int32 EntityId)
{
	const FEntityWorld& World = EntityUtil::GetEntityWorld(WorldContextObject);
	const EEntity Entity = EntityUtil::ToEntity(EntityId);

	return World.Valid(Entity) && EntityId != 0;
}

FVector UEntityLibrary::GetWorldPosition(const UObject* WorldContextObject, const int32 EntityId)
{
	FEntityWorld& World = EntityUtil::GetEntityWorld(WorldContextObject);
	const EEntity Entity = EntityUtil::ToEntity(EntityId);

	return World.GetWorldPosition(Entity);
}

FRotator UEntityLibrary::GetWorldRotation(const UObject* WorldContextObject, const int32 EntityId)
{
	FEntityWorld& World = EntityUtil::GetEntityWorld(WorldContextObject);
	const EEntity Entity = EntityUtil::ToEntity(EntityId);

	return World.GetWorldRotation(Entity);
}

FVector UEntityLibrary::GetWorldScale(const UObject* WorldContextObject, const int32 EntityId)
{
	FEntityWorld& World = EntityUtil::GetEntityWorld(WorldContextObject);
	const EEntity Entity = EntityUtil::ToEntity(EntityId);

	return World.GetWorldScale(Entity);
}
