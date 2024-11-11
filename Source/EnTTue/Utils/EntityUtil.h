#pragma once

#include <EnTTue/Utils/EntityBuilderUtil.h>

#include "EnTTue/Include.h"
#include "EnTTue/Components/BaseComponents.h"

#include "Engine/World.h"

#include "EntityUtil.generated.h"

UCLASS(BlueprintType)
class ENTTUE_API UEntityLibrary : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static bool GetSingletonByName(const UObject* WorldContextObject, const FName& Name, int32& OutEntity);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static bool IsValidEntity(const UObject* WorldContextObject, const int32 EntityId);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static FVector GetWorldPosition(const UObject* WorldContextObject, const int32 EntityId);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static FRotator GetWorldRotation(const UObject* WorldContextObject, const int32 EntityId);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static FVector GetWorldScale(const UObject* WorldContextObject, const int32 EntityId);
};

namespace EntityUtil {
	ENTTUE_API EEntity ToEntity(uint32 Id);
	ENTTUE_API EEntity ToEntity(int32 Id);
	
	ENTTUE_API uint32 ToUint32(EEntity Entity);
	ENTTUE_API int32 ToInt32(EEntity Entity);
	
	ENTTUE_API FEntityWorld& GetEntityWorld(const UObject* WorldContextObject);

	ENTTUE_API void AddSingletonEntity(FEntityWorld& World, const FName Name, const EEntity Entity);

	template<typename SingletonType>
	void AddSingletonEntity(FEntityWorld& World, const FName Name, const EEntity Entity)
	{
		if (World.SingletonEntities.Contains(Name)) {
			UE_LOG(LogECS, Error, TEXT("Trying to Recreate singleton: %s"), *Name.ToString());
		} else {
			World.Emplace<SingletonType>(Entity);
			World.SingletonEntities.Add(Name, Entity);
		}
	}
	
	template<typename SingletonType>
	EEntity GetOrAddSingletonEntity(FEntityWorld& World, const FName Name)
	{
		if (World.SingletonEntities.Contains(Name)) {
			if (!World.AllOf<SingletonType>(World.SingletonEntities[Name]))
			{
				World.Emplace<SingletonType>(World.SingletonEntities[Name]);
			}
			return World.SingletonEntities[Name];
		}

		const EEntity Entity = EntityBuilderUtil::CreateEntity(World, Name, FTransform::Identity);
		World.Emplace<SingletonType>(Entity);
		World.SingletonEntities.Add(Name, Entity);

		UE_LOG(LogTemp, Display, TEXT("Created singleton: %s"), *Name.ToString());

		return Entity;
	}

	template<typename SingletonType>
	EEntity GetSingletonEntity(FEntityWorld& World)
	{
		return World.View<SingletonType>().front();
	}

	ENTTUE_API bool GetSingletonEntity(FEntityWorld& World, const FName Name, EEntity& Entity);

	template<typename Func>
	void ForEachRelative(FEntityWorld& World, EEntity Entity, const bool IncludeRoot, Func&& Function) {
		// Process the current entity
		if (IncludeRoot) {
			Function(Entity);
		}
    
		// If the entity has children, process them recursively
		if (auto* ChildrenComponent = World.TryGet<FChildrenComponent>(Entity)) {
			for (EEntity Child : ChildrenComponent->Children) {
				ForEachRelative(World, Child, true, Function);
			}
		}
	}

	template<typename Func>
	void ForEachParent(FEntityWorld& World, EEntity Entity, const bool IncludeRoot, Func&& Function) {
		// Process the current entity
		if (IncludeRoot) {
			Function(Entity);
		}
	
		// If the entity has a parent, process it
		if (auto* ParentComponent = World.TryGet<FParentComponent>(Entity)) {
			ForEachParent(World, ParentComponent->Parent, true, Function);
		}
	}

	template<typename T>
	EEntity FindChildWithComponent(FEntityWorld& World, EEntity Entity, const bool IncludeRoot)
	{
		EEntity FoundEntity = entt::null;

		ForEachRelative(World, Entity, IncludeRoot, [&](const EEntity RelativeEntity) -> bool {
			if (World.AllOf<T>(RelativeEntity)) {
				FoundEntity = RelativeEntity;
				return false; // Return false to indicate that the entity has been found and iteration should stop
			}
			return true; // Return true to continue iterating
		});

		return FoundEntity;
	}

	template<typename T>
	EEntity FindParentWithComponent(FEntityWorld& World, EEntity Entity, const bool IncludeRoot)
	{
		EEntity FoundEntity = entt::null;

		ForEachParent(World, Entity, IncludeRoot, [&](const EEntity ParentEntity) -> bool {
			if (World.AllOf<T>(ParentEntity)) {
				FoundEntity = ParentEntity;
				return false; // Return false to indicate that the entity has been found and iteration should stop
			}
			return true; // Return true to continue iterating
		});

		return FoundEntity;
	}
}
