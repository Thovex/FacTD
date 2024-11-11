#pragma once

// EnTT
#include "entity/fwd.hpp"
#include "entity/registry.hpp"

// UE
#include <Dom/JsonObject.h>
#include <Engine/DataTable.h>

#include "CoreMinimal.h"

struct ENTTUE_API FWorldTime
{
	uint64 TickIndex = 0ull;
};

struct FEventComponent {
	FName EventName;
};

using EEntity = entt::entity;
using FRegistry = entt::registry;

struct ENTTUE_API FEntityWorld {
	FRegistry Registry;
	
	FRegistry OutgoingEvents;
	FRegistry IncomingEvents;
	
	EEntity RootEntity = entt::null;
	
	TMap<FName, EEntity> SingletonEntities = {};

	FWorldTime Time;

	template <typename Func>
	std::enable_if_t<std::is_invocable_v<Func, entt::type_info>, void>
	VisitComponents(const EEntity Entity, Func&& Function) {
		for (auto [id, pool] : Registry.storage()) {
			if (pool.contains(Entity)) {
				if constexpr (std::is_same_v<std::invoke_result_t<Func, entt::type_info>, void>) {
					std::invoke(Function, pool.type());
				} else {
					if (std::invoke(Function, pool.type())) {
						return;
					}
				}
			}
		}
	}

	[[nodiscard]] decltype(auto) Create() {
		return Registry.create();
	}

	EEntity GetRootEntity() const {
		return RootEntity;
	}

	template<typename ...Component>
	decltype(auto) Emplace(const EEntity Entity) {
		return (Registry.emplace<Component>(Entity), ...);
	}
	
	template<typename ...Component, typename ...Args>
	decltype(auto) Emplace(const EEntity Entity, Args&&... Arguments) {
		return Registry.emplace<Component...>(Entity, std::forward<Args>(Arguments)...);
	}

	template<typename ...Component, typename ...Args>
		decltype(auto) Replace(const EEntity Entity, Args&&... Arguments) {
		return Registry.replace<Component...>(Entity, std::forward<Args>(Arguments)...);
	}
	
	template<typename ...Component>
	decltype(auto) EmplaceOrReplace(const EEntity Entity) {
		return (Registry.emplace_or_replace<Component>(Entity), ...);
	}

	template<typename ...Component, typename ...Args>
	decltype(auto) EmplaceOrReplace(const EEntity Entity, Args&&... Arguments) {
		return Registry.emplace_or_replace<Component...>(Entity, std::forward<Args>(Arguments)...);
	}

	template <typename ...Component>
	[[nodiscard]] decltype(auto) Get(const EEntity Entity) {
		return Registry.get<Component...>(Entity);
	}

	template <typename ...Component>
	[[nodiscard]] decltype(auto) TryGet(const EEntity Entity) {
		return Registry.try_get<Component...>(Entity);
	}

	template <typename ...Component>
	[[nodiscard]] decltype(auto) GetOrEmplace(const EEntity Entity) {
		return Registry.get_or_emplace<Component...>(Entity);
	}

	template <typename ...Component>
	[[nodiscard]] decltype(auto) AllOf(const EEntity Entity) const {
		return Registry.all_of<Component...>(Entity);
	}
	
	template <typename ...Component>
	decltype(auto) Remove(const EEntity Entity) {
		return Registry.remove<Component...>(Entity);
	}

	template <typename ...Component>
	decltype(auto) Erase(const EEntity Entity) {
		return Registry.erase<Component...>(Entity);
	}

	template <typename ...Component>
	[[nodiscard]] decltype(auto) View() {
		
		return Registry.view<Component...>();
	}
	
	template <typename ...Component, typename... Exclude>
	[[nodiscard]] decltype(auto) View(entt::exclude_t<Exclude...> Exclusion) {
		return Registry.view<Component...>(Exclusion);
	}

	[[nodiscard]] decltype(auto) ForEachEntity() {
		return Registry.storage<EEntity>().each();
	}

	template <typename ...Component>
	[[nodiscard]] decltype(auto) ForEach() {
		return Registry.view<Component...>().each();
	}
	
	template <typename ...Component>
	[[nodiscard]] decltype(auto) OnEvent() {
		return IncomingEvents.view<Component...>();
	}

	template <typename ...Component>
	[[nodiscard]] decltype(auto) OnEachEvent() {
		return IncomingEvents.view<Component...>().each();
	}

	template<typename... Event>
	void Emit(Event&&... Events) {
		const EEntity EventEntity = OutgoingEvents.create();
		(OutgoingEvents.emplace<std::decay_t<Event>>(EventEntity, std::forward<Event>(Events)), ...);

		FString EventTypes;
		(EventTypes.Append( TCHAR_TO_ANSI(*FString(TEXT("[") + std::decay_t<Event>::StaticStruct()->GetName() + TEXT("],")))), ...);
		EventTypes.RemoveFromEnd(TEXT(","));
	
		OutgoingEvents.emplace<FEventComponent>(EventEntity, FEventComponent { .EventName = FName(*EventTypes) });
	}

	template <typename ...Component, typename... Exclude>
	[[nodiscard]] decltype(auto) ForEach(entt::exclude_t<Exclude...> Exclusion) {
		return Registry.view<Component...>(Exclusion).each();
	}

	template <typename ...Component, typename Func>
	decltype(auto) Patch(const EEntity Entity, Func&& Function) {
		return Registry.patch<Component...>(Entity, std::forward<Func>(Function));
	}
	
	template<typename Type>
	decltype(auto) OnUpdate(const entt::id_type Id = entt::type_hash<Type>::value()) {
		return Registry.on_update<Type>(Id);
	}

	template<typename Type>
	auto OnConstruct(const entt::id_type Id = entt::type_hash<Type>::value()) {
		return Registry.on_construct<Type>(Id);
	}

	template<typename Type>
	auto OnDestroy(const entt::id_type Id = entt::type_hash<Type>::value()) {
		return Registry.on_destroy<Type>(Id);
	}
	
	bool Valid (const EEntity Entity) const {
		return Registry.valid(Entity);
	}

	static UDataTable* GetDataTable(const FString& Path);

	void Save();
	void Load();

	FVector GetWorldPosition(const EEntity Entity);
	FRotator GetWorldRotation(const EEntity Entity);
	FVector GetWorldScale(const EEntity Entity);
};
