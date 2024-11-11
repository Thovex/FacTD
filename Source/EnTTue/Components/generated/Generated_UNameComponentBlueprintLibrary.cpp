#include "Generated_UNameComponentBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

// Copyright Jesse van Vliet (2024 - AND BEYOND!)

void UNameComponentBlueprintLibrary::Emplace_NameComponent(UObject* WorldContextObject, const int32 EntityId, const FNameComponent& NameComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FNameComponent>(Entity, NameComponent);
}

void UNameComponentBlueprintLibrary::EmplaceOrReplace_NameComponent(UObject* WorldContextObject, const int32 EntityId, const FNameComponent& NameComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FNameComponent>(Entity, NameComponent);
}

void UNameComponentBlueprintLibrary::Replace_NameComponent(UObject* WorldContextObject, const int32 EntityId, const FNameComponent& NameComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Replace<FNameComponent>(Entity, NameComponent);
}

bool UNameComponentBlueprintLibrary::AllOf_NameComponent(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FNameComponent>(Entity);
}

UNameComponentWrapper* UNameComponentBlueprintLibrary::TryGet_NameComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);

    if (FNameComponent* Ptr = EntityWorld.TryGet<FNameComponent>(Entity)) 
    {
        auto* Wrapper = NewObject<UNameComponentWrapper>();
        Wrapper->Set(Ptr);
        return Wrapper;
    }
    return nullptr;
}

void UNameComponentBlueprintLibrary::Get_NameComponent(UObject* WorldContextObject, const int32 EntityId, FNameComponent& OutNameComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    OutNameComponent = EntityWorld.Get<FNameComponent>(Entity);
}

void UNameComponentBlueprintLibrary::Remove_NameComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FNameComponent>(Entity);
}

void UNameComponentBlueprintLibrary::Erase_NameComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FNameComponent>(Entity);
}

int32 UNameComponentBlueprintLibrary::MetaType_NameComponent(UObject* WorldContextObject)
{
    return entt::resolve<FNameComponent>().id();
}
