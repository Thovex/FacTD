#include "Generated_UFacTD_BeltItemComponentBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

// Copyright Jesse van Vliet (2024 - AND BEYOND!)

void UFacTD_BeltItemComponentBlueprintLibrary::Emplace_FacTD_BeltItemComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_BeltItemComponent& FacTD_BeltItemComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FFacTD_BeltItemComponent>(Entity, FacTD_BeltItemComponent);
}

void UFacTD_BeltItemComponentBlueprintLibrary::EmplaceOrReplace_FacTD_BeltItemComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_BeltItemComponent& FacTD_BeltItemComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FFacTD_BeltItemComponent>(Entity, FacTD_BeltItemComponent);
}

void UFacTD_BeltItemComponentBlueprintLibrary::Replace_FacTD_BeltItemComponent(UObject* WorldContextObject, const int32 EntityId, const FFacTD_BeltItemComponent& FacTD_BeltItemComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Replace<FFacTD_BeltItemComponent>(Entity, FacTD_BeltItemComponent);
}

bool UFacTD_BeltItemComponentBlueprintLibrary::AllOf_FacTD_BeltItemComponent(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FFacTD_BeltItemComponent>(Entity);
}

UFacTD_BeltItemComponentWrapper* UFacTD_BeltItemComponentBlueprintLibrary::TryGet_FacTD_BeltItemComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);

    if (FFacTD_BeltItemComponent* Ptr = EntityWorld.TryGet<FFacTD_BeltItemComponent>(Entity)) 
    {
        auto* Wrapper = NewObject<UFacTD_BeltItemComponentWrapper>();
        Wrapper->Set(Ptr);
        return Wrapper;
    }
    return nullptr;
}

void UFacTD_BeltItemComponentBlueprintLibrary::Get_FacTD_BeltItemComponent(UObject* WorldContextObject, const int32 EntityId, FFacTD_BeltItemComponent& OutFacTD_BeltItemComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    OutFacTD_BeltItemComponent = EntityWorld.Get<FFacTD_BeltItemComponent>(Entity);
}

void UFacTD_BeltItemComponentBlueprintLibrary::Remove_FacTD_BeltItemComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FFacTD_BeltItemComponent>(Entity);
}

void UFacTD_BeltItemComponentBlueprintLibrary::Erase_FacTD_BeltItemComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FFacTD_BeltItemComponent>(Entity);
}

int32 UFacTD_BeltItemComponentBlueprintLibrary::MetaType_FacTD_BeltItemComponent(UObject* WorldContextObject)
{
    return entt::resolve<FFacTD_BeltItemComponent>().id();
}
