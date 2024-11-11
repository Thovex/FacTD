#include "Generated_UFacTD_GridCellComponentBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

// Copyright Jesse van Vliet (2024 - AND BEYOND!)

void UFacTD_GridCellComponentBlueprintLibrary::Emplace_FacTD_GridCellComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_GridCellComponent& FacTD_GridCellComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FFacTD_GridCellComponent>(Entity, FacTD_GridCellComponent);
}

void UFacTD_GridCellComponentBlueprintLibrary::EmplaceOrReplace_FacTD_GridCellComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_GridCellComponent& FacTD_GridCellComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FFacTD_GridCellComponent>(Entity, FacTD_GridCellComponent);
}

void UFacTD_GridCellComponentBlueprintLibrary::Replace_FacTD_GridCellComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_GridCellComponent& FacTD_GridCellComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Replace<FFacTD_GridCellComponent>(Entity, FacTD_GridCellComponent);
}

bool UFacTD_GridCellComponentBlueprintLibrary::AllOf_FacTD_GridCellComponent(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FFacTD_GridCellComponent>(Entity);
}

UFacTD_GridCellComponentWrapper* UFacTD_GridCellComponentBlueprintLibrary::TryGet_FacTD_GridCellComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);

    if (FFacTD_GridCellComponent* Ptr = EntityWorld.TryGet<FFacTD_GridCellComponent>(Entity)) 
    {
        auto* Wrapper = NewObject<UFacTD_GridCellComponentWrapper>();
        Wrapper->Set(Ptr);
        return Wrapper;
    }
    return nullptr;
}

void UFacTD_GridCellComponentBlueprintLibrary::Get_FacTD_GridCellComponent(UObject* WorldContextObject, const int32 EntityId, FFacTD_GridCellComponent& OutFacTD_GridCellComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    OutFacTD_GridCellComponent = EntityWorld.Get<FFacTD_GridCellComponent>(Entity);
}

void UFacTD_GridCellComponentBlueprintLibrary::Remove_FacTD_GridCellComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FFacTD_GridCellComponent>(Entity);
}

void UFacTD_GridCellComponentBlueprintLibrary::Erase_FacTD_GridCellComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FFacTD_GridCellComponent>(Entity);
}

int32 UFacTD_GridCellComponentBlueprintLibrary::MetaType_FacTD_GridCellComponent(UObject* WorldContextObject)
{
    return entt::resolve<FFacTD_GridCellComponent>().id();
}
