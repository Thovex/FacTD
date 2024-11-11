#include "Generated_UScaleComponentBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

// Copyright Jesse van Vliet (2024 - AND BEYOND!)

void UScaleComponentBlueprintLibrary::Emplace_ScaleComponent(UObject* WorldContextObject, const int32 EntityId, const FScaleComponent& ScaleComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FScaleComponent>(Entity, ScaleComponent);
}

void UScaleComponentBlueprintLibrary::EmplaceOrReplace_ScaleComponent(UObject* WorldContextObject, const int32 EntityId, const FScaleComponent& ScaleComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FScaleComponent>(Entity, ScaleComponent);
}

void UScaleComponentBlueprintLibrary::Replace_ScaleComponent(UObject* WorldContextObject, const int32 EntityId, const FScaleComponent& ScaleComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Replace<FScaleComponent>(Entity, ScaleComponent);
}

bool UScaleComponentBlueprintLibrary::AllOf_ScaleComponent(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FScaleComponent>(Entity);
}

UScaleComponentWrapper* UScaleComponentBlueprintLibrary::TryGet_ScaleComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);

    if (FScaleComponent* Ptr = EntityWorld.TryGet<FScaleComponent>(Entity)) 
    {
        auto* Wrapper = NewObject<UScaleComponentWrapper>();
        Wrapper->Set(Ptr);
        return Wrapper;
    }
    return nullptr;
}

void UScaleComponentBlueprintLibrary::Get_ScaleComponent(UObject* WorldContextObject, const int32 EntityId, FScaleComponent& OutScaleComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    OutScaleComponent = EntityWorld.Get<FScaleComponent>(Entity);
}

void UScaleComponentBlueprintLibrary::Remove_ScaleComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FScaleComponent>(Entity);
}

void UScaleComponentBlueprintLibrary::Erase_ScaleComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FScaleComponent>(Entity);
}

int32 UScaleComponentBlueprintLibrary::MetaType_ScaleComponent(UObject* WorldContextObject)
{
    return entt::resolve<FScaleComponent>().id();
}
