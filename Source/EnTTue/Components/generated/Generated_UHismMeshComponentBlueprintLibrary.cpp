#include "Generated_UHismMeshComponentBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

// Copyright Jesse van Vliet (2024 - AND BEYOND!)

void UHismMeshComponentBlueprintLibrary::Emplace_HismMeshComponent(UObject* WorldContextObject, const int32 EntityId, const FHismMeshComponent& HismMeshComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FHismMeshComponent>(Entity, HismMeshComponent);
}

void UHismMeshComponentBlueprintLibrary::EmplaceOrReplace_HismMeshComponent(UObject* WorldContextObject, const int32 EntityId, const FHismMeshComponent& HismMeshComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FHismMeshComponent>(Entity, HismMeshComponent);
}

void UHismMeshComponentBlueprintLibrary::Replace_HismMeshComponent(UObject* WorldContextObject, const int32 EntityId, const FHismMeshComponent& HismMeshComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Replace<FHismMeshComponent>(Entity, HismMeshComponent);
}

bool UHismMeshComponentBlueprintLibrary::AllOf_HismMeshComponent(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FHismMeshComponent>(Entity);
}

UHismMeshComponentWrapper* UHismMeshComponentBlueprintLibrary::TryGet_HismMeshComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);

    if (FHismMeshComponent* Ptr = EntityWorld.TryGet<FHismMeshComponent>(Entity)) 
    {
        auto* Wrapper = NewObject<UHismMeshComponentWrapper>();
        Wrapper->Set(Ptr);
        return Wrapper;
    }
    return nullptr;
}

void UHismMeshComponentBlueprintLibrary::Get_HismMeshComponent(UObject* WorldContextObject, const int32 EntityId, FHismMeshComponent& OutHismMeshComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    OutHismMeshComponent = EntityWorld.Get<FHismMeshComponent>(Entity);
}

void UHismMeshComponentBlueprintLibrary::Remove_HismMeshComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FHismMeshComponent>(Entity);
}

void UHismMeshComponentBlueprintLibrary::Erase_HismMeshComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FHismMeshComponent>(Entity);
}

int32 UHismMeshComponentBlueprintLibrary::MetaType_HismMeshComponent(UObject* WorldContextObject)
{
    return entt::resolve<FHismMeshComponent>().id();
}
