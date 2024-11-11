#include "Generated_UVelocityComponentBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

// Copyright Jesse van Vliet (2024 - AND BEYOND!)

void UVelocityComponentBlueprintLibrary::Emplace_VelocityComponent(UObject* WorldContextObject, const int32 EntityId, const FVelocityComponent& VelocityComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FVelocityComponent>(Entity, VelocityComponent);
}

void UVelocityComponentBlueprintLibrary::EmplaceOrReplace_VelocityComponent(UObject* WorldContextObject, const int32 EntityId, const FVelocityComponent& VelocityComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FVelocityComponent>(Entity, VelocityComponent);
}

void UVelocityComponentBlueprintLibrary::Replace_VelocityComponent(UObject* WorldContextObject, const int32 EntityId, const FVelocityComponent& VelocityComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Replace<FVelocityComponent>(Entity, VelocityComponent);
}

bool UVelocityComponentBlueprintLibrary::AllOf_VelocityComponent(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FVelocityComponent>(Entity);
}

UVelocityComponentWrapper* UVelocityComponentBlueprintLibrary::TryGet_VelocityComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);

    if (FVelocityComponent* Ptr = EntityWorld.TryGet<FVelocityComponent>(Entity)) 
    {
        auto* Wrapper = NewObject<UVelocityComponentWrapper>();
        Wrapper->Set(Ptr);
        return Wrapper;
    }
    return nullptr;
}

void UVelocityComponentBlueprintLibrary::Get_VelocityComponent(UObject* WorldContextObject, const int32 EntityId, FVelocityComponent& OutVelocityComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    OutVelocityComponent = EntityWorld.Get<FVelocityComponent>(Entity);
}

void UVelocityComponentBlueprintLibrary::Remove_VelocityComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FVelocityComponent>(Entity);
}

void UVelocityComponentBlueprintLibrary::Erase_VelocityComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FVelocityComponent>(Entity);
}

int32 UVelocityComponentBlueprintLibrary::MetaType_VelocityComponent(UObject* WorldContextObject)
{
    return entt::resolve<FVelocityComponent>().id();
}
