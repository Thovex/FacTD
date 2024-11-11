#include "Generated_USkMeshComponentBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

// Copyright Jesse van Vliet (2024 - AND BEYOND!)

void USkMeshComponentBlueprintLibrary::Emplace_SkMeshComponent(UObject* WorldContextObject, const int32 EntityId, const FSkMeshComponent& SkMeshComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FSkMeshComponent>(Entity, SkMeshComponent);
}

void USkMeshComponentBlueprintLibrary::EmplaceOrReplace_SkMeshComponent(UObject* WorldContextObject, const int32 EntityId, const FSkMeshComponent& SkMeshComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FSkMeshComponent>(Entity, SkMeshComponent);
}

void USkMeshComponentBlueprintLibrary::Replace_SkMeshComponent(UObject* WorldContextObject, const int32 EntityId, const FSkMeshComponent& SkMeshComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Replace<FSkMeshComponent>(Entity, SkMeshComponent);
}

bool USkMeshComponentBlueprintLibrary::AllOf_SkMeshComponent(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FSkMeshComponent>(Entity);
}

USkMeshComponentWrapper* USkMeshComponentBlueprintLibrary::TryGet_SkMeshComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);

    if (FSkMeshComponent* Ptr = EntityWorld.TryGet<FSkMeshComponent>(Entity)) 
    {
        auto* Wrapper = NewObject<USkMeshComponentWrapper>();
        Wrapper->Set(Ptr);
        return Wrapper;
    }
    return nullptr;
}

void USkMeshComponentBlueprintLibrary::Get_SkMeshComponent(UObject* WorldContextObject, const int32 EntityId, FSkMeshComponent& OutSkMeshComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    OutSkMeshComponent = EntityWorld.Get<FSkMeshComponent>(Entity);
}

void USkMeshComponentBlueprintLibrary::Remove_SkMeshComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FSkMeshComponent>(Entity);
}

void USkMeshComponentBlueprintLibrary::Erase_SkMeshComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FSkMeshComponent>(Entity);
}

int32 USkMeshComponentBlueprintLibrary::MetaType_SkMeshComponent(UObject* WorldContextObject)
{
    return entt::resolve<FSkMeshComponent>().id();
}
