#include "Generated_UFacTD_GridComponentBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

// Copyright Jesse van Vliet (2024 - AND BEYOND!)

void UFacTD_GridComponentBlueprintLibrary::Emplace_FacTD_GridComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_GridComponent& FacTD_GridComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FFacTD_GridComponent>(Entity, FacTD_GridComponent);
}

void UFacTD_GridComponentBlueprintLibrary::EmplaceOrReplace_FacTD_GridComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_GridComponent& FacTD_GridComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FFacTD_GridComponent>(Entity, FacTD_GridComponent);
}

void UFacTD_GridComponentBlueprintLibrary::Replace_FacTD_GridComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_GridComponent& FacTD_GridComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Replace<FFacTD_GridComponent>(Entity, FacTD_GridComponent);
}

bool UFacTD_GridComponentBlueprintLibrary::AllOf_FacTD_GridComponent(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FFacTD_GridComponent>(Entity);
}

UFacTD_GridComponentWrapper* UFacTD_GridComponentBlueprintLibrary::TryGet_FacTD_GridComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);

    if (FFacTD_GridComponent* Ptr = EntityWorld.TryGet<FFacTD_GridComponent>(Entity)) 
    {
        auto* Wrapper = NewObject<UFacTD_GridComponentWrapper>();
        Wrapper->Set(Ptr);
        return Wrapper;
    }
    return nullptr;
}

void UFacTD_GridComponentBlueprintLibrary::Get_FacTD_GridComponent(UObject* WorldContextObject, const int32 EntityId, FFacTD_GridComponent& OutFacTD_GridComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    OutFacTD_GridComponent = EntityWorld.Get<FFacTD_GridComponent>(Entity);
}

void UFacTD_GridComponentBlueprintLibrary::Remove_FacTD_GridComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FFacTD_GridComponent>(Entity);
}

void UFacTD_GridComponentBlueprintLibrary::Erase_FacTD_GridComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FFacTD_GridComponent>(Entity);
}

int32 UFacTD_GridComponentBlueprintLibrary::MetaType_FacTD_GridComponent(UObject* WorldContextObject)
{
    return entt::resolve<FFacTD_GridComponent>().id();
}
