#include "Generated_URotationComponentBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

// Copyright Jesse van Vliet (2024 - AND BEYOND!)

void URotationComponentBlueprintLibrary::Emplace_RotationComponent(UObject* WorldContextObject, const int32 EntityId, const FRotationComponent& RotationComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FRotationComponent>(Entity, RotationComponent);
}

void URotationComponentBlueprintLibrary::EmplaceOrReplace_RotationComponent(UObject* WorldContextObject, const int32 EntityId, const FRotationComponent& RotationComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FRotationComponent>(Entity, RotationComponent);
}

void URotationComponentBlueprintLibrary::Replace_RotationComponent(UObject* WorldContextObject, const int32 EntityId, const FRotationComponent& RotationComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Replace<FRotationComponent>(Entity, RotationComponent);
}

bool URotationComponentBlueprintLibrary::AllOf_RotationComponent(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FRotationComponent>(Entity);
}

URotationComponentWrapper* URotationComponentBlueprintLibrary::TryGet_RotationComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);

    if (FRotationComponent* Ptr = EntityWorld.TryGet<FRotationComponent>(Entity)) 
    {
        auto* Wrapper = NewObject<URotationComponentWrapper>();
        Wrapper->Set(Ptr);
        return Wrapper;
    }
    return nullptr;
}

void URotationComponentBlueprintLibrary::Get_RotationComponent(UObject* WorldContextObject, const int32 EntityId, FRotationComponent& OutRotationComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    OutRotationComponent = EntityWorld.Get<FRotationComponent>(Entity);
}

void URotationComponentBlueprintLibrary::Remove_RotationComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FRotationComponent>(Entity);
}

void URotationComponentBlueprintLibrary::Erase_RotationComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FRotationComponent>(Entity);
}

int32 URotationComponentBlueprintLibrary::MetaType_RotationComponent(UObject* WorldContextObject)
{
    return entt::resolve<FRotationComponent>().id();
}
