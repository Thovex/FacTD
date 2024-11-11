#include "Generated_UFacTD_DirectionComponentBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

// Copyright Jesse van Vliet (2024 - AND BEYOND!)

void UFacTD_DirectionComponentBlueprintLibrary::Emplace_FacTD_DirectionComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_DirectionComponent& FacTD_DirectionComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FFacTD_DirectionComponent>(Entity, FacTD_DirectionComponent);
}

void UFacTD_DirectionComponentBlueprintLibrary::EmplaceOrReplace_FacTD_DirectionComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_DirectionComponent& FacTD_DirectionComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FFacTD_DirectionComponent>(Entity, FacTD_DirectionComponent);
}

void UFacTD_DirectionComponentBlueprintLibrary::Replace_FacTD_DirectionComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_DirectionComponent& FacTD_DirectionComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Replace<FFacTD_DirectionComponent>(Entity, FacTD_DirectionComponent);
}

bool UFacTD_DirectionComponentBlueprintLibrary::AllOf_FacTD_DirectionComponent(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FFacTD_DirectionComponent>(Entity);
}

UFacTD_DirectionComponentWrapper* UFacTD_DirectionComponentBlueprintLibrary::TryGet_FacTD_DirectionComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);

    if (FFacTD_DirectionComponent* Ptr = EntityWorld.TryGet<FFacTD_DirectionComponent>(Entity)) 
    {
        auto* Wrapper = NewObject<UFacTD_DirectionComponentWrapper>();
        Wrapper->Set(Ptr);
        return Wrapper;
    }
    return nullptr;
}

void UFacTD_DirectionComponentBlueprintLibrary::Get_FacTD_DirectionComponent(UObject* WorldContextObject, const int32 EntityId, FFacTD_DirectionComponent& OutFacTD_DirectionComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    OutFacTD_DirectionComponent = EntityWorld.Get<FFacTD_DirectionComponent>(Entity);
}

void UFacTD_DirectionComponentBlueprintLibrary::Remove_FacTD_DirectionComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FFacTD_DirectionComponent>(Entity);
}

void UFacTD_DirectionComponentBlueprintLibrary::Erase_FacTD_DirectionComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FFacTD_DirectionComponent>(Entity);
}

int32 UFacTD_DirectionComponentBlueprintLibrary::MetaType_FacTD_DirectionComponent(UObject* WorldContextObject)
{
    return entt::resolve<FFacTD_DirectionComponent>().id();
}
