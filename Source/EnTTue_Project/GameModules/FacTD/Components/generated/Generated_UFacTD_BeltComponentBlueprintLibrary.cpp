#include "Generated_UFacTD_BeltComponentBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

// Copyright Jesse van Vliet (2024 - AND BEYOND!)

void UFacTD_BeltComponentBlueprintLibrary::Emplace_FacTD_BeltComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_BeltComponent& FacTD_BeltComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FFacTD_BeltComponent>(Entity, FacTD_BeltComponent);
}

void UFacTD_BeltComponentBlueprintLibrary::EmplaceOrReplace_FacTD_BeltComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_BeltComponent& FacTD_BeltComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FFacTD_BeltComponent>(Entity, FacTD_BeltComponent);
}

void UFacTD_BeltComponentBlueprintLibrary::Replace_FacTD_BeltComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_BeltComponent& FacTD_BeltComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Replace<FFacTD_BeltComponent>(Entity, FacTD_BeltComponent);
}

bool UFacTD_BeltComponentBlueprintLibrary::AllOf_FacTD_BeltComponent(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FFacTD_BeltComponent>(Entity);
}

UFacTD_BeltComponentWrapper* UFacTD_BeltComponentBlueprintLibrary::TryGet_FacTD_BeltComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);

    if (FFacTD_BeltComponent* Ptr = EntityWorld.TryGet<FFacTD_BeltComponent>(Entity)) 
    {
        auto* Wrapper = NewObject<UFacTD_BeltComponentWrapper>();
        Wrapper->Set(Ptr);
        return Wrapper;
    }
    return nullptr;
}

void UFacTD_BeltComponentBlueprintLibrary::Get_FacTD_BeltComponent(UObject* WorldContextObject, const int32 EntityId, FFacTD_BeltComponent& OutFacTD_BeltComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    OutFacTD_BeltComponent = EntityWorld.Get<FFacTD_BeltComponent>(Entity);
}

void UFacTD_BeltComponentBlueprintLibrary::Remove_FacTD_BeltComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FFacTD_BeltComponent>(Entity);
}

void UFacTD_BeltComponentBlueprintLibrary::Erase_FacTD_BeltComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FFacTD_BeltComponent>(Entity);
}

int32 UFacTD_BeltComponentBlueprintLibrary::MetaType_FacTD_BeltComponent(UObject* WorldContextObject)
{
    return entt::resolve<FFacTD_BeltComponent>().id();
}
