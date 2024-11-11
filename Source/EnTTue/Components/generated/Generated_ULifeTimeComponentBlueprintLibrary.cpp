#include "Generated_ULifeTimeComponentBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

// Copyright Jesse van Vliet (2024 - AND BEYOND!)

void ULifeTimeComponentBlueprintLibrary::Emplace_LifeTimeComponent(UObject* WorldContextObject, const int32 EntityId, const FLifeTimeComponent& LifeTimeComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FLifeTimeComponent>(Entity, LifeTimeComponent);
}

void ULifeTimeComponentBlueprintLibrary::EmplaceOrReplace_LifeTimeComponent(UObject* WorldContextObject, const int32 EntityId, const FLifeTimeComponent& LifeTimeComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FLifeTimeComponent>(Entity, LifeTimeComponent);
}

void ULifeTimeComponentBlueprintLibrary::Replace_LifeTimeComponent(UObject* WorldContextObject, const int32 EntityId, const FLifeTimeComponent& LifeTimeComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Replace<FLifeTimeComponent>(Entity, LifeTimeComponent);
}

bool ULifeTimeComponentBlueprintLibrary::AllOf_LifeTimeComponent(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FLifeTimeComponent>(Entity);
}

ULifeTimeComponentWrapper* ULifeTimeComponentBlueprintLibrary::TryGet_LifeTimeComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);

    if (FLifeTimeComponent* Ptr = EntityWorld.TryGet<FLifeTimeComponent>(Entity)) 
    {
        auto* Wrapper = NewObject<ULifeTimeComponentWrapper>();
        Wrapper->Set(Ptr);
        return Wrapper;
    }
    return nullptr;
}

void ULifeTimeComponentBlueprintLibrary::Get_LifeTimeComponent(UObject* WorldContextObject, const int32 EntityId, FLifeTimeComponent& OutLifeTimeComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    OutLifeTimeComponent = EntityWorld.Get<FLifeTimeComponent>(Entity);
}

void ULifeTimeComponentBlueprintLibrary::Remove_LifeTimeComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FLifeTimeComponent>(Entity);
}

void ULifeTimeComponentBlueprintLibrary::Erase_LifeTimeComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FLifeTimeComponent>(Entity);
}

int32 ULifeTimeComponentBlueprintLibrary::MetaType_LifeTimeComponent(UObject* WorldContextObject)
{
    return entt::resolve<FLifeTimeComponent>().id();
}
