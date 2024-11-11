#include "Generated_UPositionComponentBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

// Copyright Jesse van Vliet (2024 - AND BEYOND!)

void UPositionComponentBlueprintLibrary::Emplace_PositionComponent(UObject* WorldContextObject, const int32 EntityId, const FPositionComponent& PositionComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FPositionComponent>(Entity, PositionComponent);
}

void UPositionComponentBlueprintLibrary::EmplaceOrReplace_PositionComponent(UObject* WorldContextObject, const int32 EntityId, const FPositionComponent& PositionComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FPositionComponent>(Entity, PositionComponent);
}

void UPositionComponentBlueprintLibrary::Replace_PositionComponent(UObject* WorldContextObject, const int32 EntityId, const FPositionComponent& PositionComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Replace<FPositionComponent>(Entity, PositionComponent);
}

bool UPositionComponentBlueprintLibrary::AllOf_PositionComponent(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FPositionComponent>(Entity);
}

UPositionComponentWrapper* UPositionComponentBlueprintLibrary::TryGet_PositionComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);

    if (FPositionComponent* Ptr = EntityWorld.TryGet<FPositionComponent>(Entity)) 
    {
        auto* Wrapper = NewObject<UPositionComponentWrapper>();
        Wrapper->Set(Ptr);
        return Wrapper;
    }
    return nullptr;
}

void UPositionComponentBlueprintLibrary::Get_PositionComponent(UObject* WorldContextObject, const int32 EntityId, FPositionComponent& OutPositionComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    OutPositionComponent = EntityWorld.Get<FPositionComponent>(Entity);
}

void UPositionComponentBlueprintLibrary::Remove_PositionComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FPositionComponent>(Entity);
}

void UPositionComponentBlueprintLibrary::Erase_PositionComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FPositionComponent>(Entity);
}

int32 UPositionComponentBlueprintLibrary::MetaType_PositionComponent(UObject* WorldContextObject)
{
    return entt::resolve<FPositionComponent>().id();
}
