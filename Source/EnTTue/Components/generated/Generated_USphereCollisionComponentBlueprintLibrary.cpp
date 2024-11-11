#include "Generated_USphereCollisionComponentBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

// Copyright Jesse van Vliet (2024 - AND BEYOND!)

void USphereCollisionComponentBlueprintLibrary::Emplace_SphereCollisionComponent(UObject* WorldContextObject, const int32 EntityId, const FSphereCollisionComponent& SphereCollisionComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FSphereCollisionComponent>(Entity, SphereCollisionComponent);
}

void USphereCollisionComponentBlueprintLibrary::EmplaceOrReplace_SphereCollisionComponent(UObject* WorldContextObject, const int32 EntityId, const FSphereCollisionComponent& SphereCollisionComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FSphereCollisionComponent>(Entity, SphereCollisionComponent);
}

void USphereCollisionComponentBlueprintLibrary::Replace_SphereCollisionComponent(UObject* WorldContextObject, const int32 EntityId, const FSphereCollisionComponent& SphereCollisionComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Replace<FSphereCollisionComponent>(Entity, SphereCollisionComponent);
}

bool USphereCollisionComponentBlueprintLibrary::AllOf_SphereCollisionComponent(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FSphereCollisionComponent>(Entity);
}

USphereCollisionComponentWrapper* USphereCollisionComponentBlueprintLibrary::TryGet_SphereCollisionComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);

    if (FSphereCollisionComponent* Ptr = EntityWorld.TryGet<FSphereCollisionComponent>(Entity)) 
    {
        auto* Wrapper = NewObject<USphereCollisionComponentWrapper>();
        Wrapper->Set(Ptr);
        return Wrapper;
    }
    return nullptr;
}

void USphereCollisionComponentBlueprintLibrary::Get_SphereCollisionComponent(UObject* WorldContextObject, const int32 EntityId, FSphereCollisionComponent& OutSphereCollisionComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    OutSphereCollisionComponent = EntityWorld.Get<FSphereCollisionComponent>(Entity);
}

void USphereCollisionComponentBlueprintLibrary::Remove_SphereCollisionComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FSphereCollisionComponent>(Entity);
}

void USphereCollisionComponentBlueprintLibrary::Erase_SphereCollisionComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FSphereCollisionComponent>(Entity);
}

int32 USphereCollisionComponentBlueprintLibrary::MetaType_SphereCollisionComponent(UObject* WorldContextObject)
{
    return entt::resolve<FSphereCollisionComponent>().id();
}
