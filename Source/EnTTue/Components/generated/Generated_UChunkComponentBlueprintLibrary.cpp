#include "Generated_UChunkComponentBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

// Copyright Jesse van Vliet (2024 - AND BEYOND!)

void UChunkComponentBlueprintLibrary::Emplace_ChunkComponent(UObject* WorldContextObject, const int32 EntityId, const FChunkComponent& ChunkComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FChunkComponent>(Entity, ChunkComponent);
}

void UChunkComponentBlueprintLibrary::EmplaceOrReplace_ChunkComponent(UObject* WorldContextObject, const int32 EntityId, const FChunkComponent& ChunkComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FChunkComponent>(Entity, ChunkComponent);
}

void UChunkComponentBlueprintLibrary::Replace_ChunkComponent(UObject* WorldContextObject, const int32 EntityId, const FChunkComponent& ChunkComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Replace<FChunkComponent>(Entity, ChunkComponent);
}

bool UChunkComponentBlueprintLibrary::AllOf_ChunkComponent(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FChunkComponent>(Entity);
}

UChunkComponentWrapper* UChunkComponentBlueprintLibrary::TryGet_ChunkComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);

    if (FChunkComponent* Ptr = EntityWorld.TryGet<FChunkComponent>(Entity)) 
    {
        auto* Wrapper = NewObject<UChunkComponentWrapper>();
        Wrapper->Set(Ptr);
        return Wrapper;
    }
    return nullptr;
}

void UChunkComponentBlueprintLibrary::Get_ChunkComponent(UObject* WorldContextObject, const int32 EntityId, FChunkComponent& OutChunkComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    OutChunkComponent = EntityWorld.Get<FChunkComponent>(Entity);
}

void UChunkComponentBlueprintLibrary::Remove_ChunkComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FChunkComponent>(Entity);
}

void UChunkComponentBlueprintLibrary::Erase_ChunkComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FChunkComponent>(Entity);
}

int32 UChunkComponentBlueprintLibrary::MetaType_ChunkComponent(UObject* WorldContextObject)
{
    return entt::resolve<FChunkComponent>().id();
}
