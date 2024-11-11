#include "Generated_UBoxCollisionComponentBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

// Copyright Jesse van Vliet (2024 - AND BEYOND!)

void UBoxCollisionComponentBlueprintLibrary::Emplace_BoxCollisionComponent(UObject* WorldContextObject, const int32 EntityId, const FBoxCollisionComponent& BoxCollisionComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FBoxCollisionComponent>(Entity, BoxCollisionComponent);
}

void UBoxCollisionComponentBlueprintLibrary::EmplaceOrReplace_BoxCollisionComponent(UObject* WorldContextObject, const int32 EntityId, const FBoxCollisionComponent& BoxCollisionComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FBoxCollisionComponent>(Entity, BoxCollisionComponent);
}

void UBoxCollisionComponentBlueprintLibrary::Replace_BoxCollisionComponent(UObject* WorldContextObject, const int32 EntityId, const FBoxCollisionComponent& BoxCollisionComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Replace<FBoxCollisionComponent>(Entity, BoxCollisionComponent);
}

bool UBoxCollisionComponentBlueprintLibrary::AllOf_BoxCollisionComponent(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FBoxCollisionComponent>(Entity);
}

UBoxCollisionComponentWrapper* UBoxCollisionComponentBlueprintLibrary::TryGet_BoxCollisionComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);

    if (FBoxCollisionComponent* Ptr = EntityWorld.TryGet<FBoxCollisionComponent>(Entity)) 
    {
        auto* Wrapper = NewObject<UBoxCollisionComponentWrapper>();
        Wrapper->Set(Ptr);
        return Wrapper;
    }
    return nullptr;
}

void UBoxCollisionComponentBlueprintLibrary::Get_BoxCollisionComponent(UObject* WorldContextObject, const int32 EntityId, FBoxCollisionComponent& OutBoxCollisionComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    OutBoxCollisionComponent = EntityWorld.Get<FBoxCollisionComponent>(Entity);
}

void UBoxCollisionComponentBlueprintLibrary::Remove_BoxCollisionComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FBoxCollisionComponent>(Entity);
}

void UBoxCollisionComponentBlueprintLibrary::Erase_BoxCollisionComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FBoxCollisionComponent>(Entity);
}

int32 UBoxCollisionComponentBlueprintLibrary::MetaType_BoxCollisionComponent(UObject* WorldContextObject)
{
    return entt::resolve<FBoxCollisionComponent>().id();
}
