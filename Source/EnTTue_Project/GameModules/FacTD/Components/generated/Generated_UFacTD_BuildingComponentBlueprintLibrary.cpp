#include "Generated_UFacTD_BuildingComponentBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

// Copyright Jesse van Vliet (2024 - AND BEYOND!)

void UFacTD_BuildingComponentBlueprintLibrary::Emplace_FacTD_BuildingComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_BuildingComponent& FacTD_BuildingComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FFacTD_BuildingComponent>(Entity, FacTD_BuildingComponent);
}

void UFacTD_BuildingComponentBlueprintLibrary::EmplaceOrReplace_FacTD_BuildingComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_BuildingComponent& FacTD_BuildingComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FFacTD_BuildingComponent>(Entity, FacTD_BuildingComponent);
}

void UFacTD_BuildingComponentBlueprintLibrary::Replace_FacTD_BuildingComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_BuildingComponent& FacTD_BuildingComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Replace<FFacTD_BuildingComponent>(Entity, FacTD_BuildingComponent);
}

bool UFacTD_BuildingComponentBlueprintLibrary::AllOf_FacTD_BuildingComponent(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FFacTD_BuildingComponent>(Entity);
}

UFacTD_BuildingComponentWrapper* UFacTD_BuildingComponentBlueprintLibrary::TryGet_FacTD_BuildingComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);

    if (FFacTD_BuildingComponent* Ptr = EntityWorld.TryGet<FFacTD_BuildingComponent>(Entity)) 
    {
        auto* Wrapper = NewObject<UFacTD_BuildingComponentWrapper>();
        Wrapper->Set(Ptr);
        return Wrapper;
    }
    return nullptr;
}

void UFacTD_BuildingComponentBlueprintLibrary::Get_FacTD_BuildingComponent(UObject* WorldContextObject, const int32 EntityId, FFacTD_BuildingComponent& OutFacTD_BuildingComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    OutFacTD_BuildingComponent = EntityWorld.Get<FFacTD_BuildingComponent>(Entity);
}

void UFacTD_BuildingComponentBlueprintLibrary::Remove_FacTD_BuildingComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FFacTD_BuildingComponent>(Entity);
}

void UFacTD_BuildingComponentBlueprintLibrary::Erase_FacTD_BuildingComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FFacTD_BuildingComponent>(Entity);
}

int32 UFacTD_BuildingComponentBlueprintLibrary::MetaType_FacTD_BuildingComponent(UObject* WorldContextObject)
{
    return entt::resolve<FFacTD_BuildingComponent>().id();
}
