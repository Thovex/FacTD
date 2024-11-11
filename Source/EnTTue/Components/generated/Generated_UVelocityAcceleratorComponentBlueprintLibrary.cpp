#include "Generated_UVelocityAcceleratorComponentBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

// Copyright Jesse van Vliet (2024 - AND BEYOND!)

void UVelocityAcceleratorComponentBlueprintLibrary::Emplace_VelocityAcceleratorComponent(UObject* WorldContextObject, const int32 EntityId, const FVelocityAcceleratorComponent& VelocityAcceleratorComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FVelocityAcceleratorComponent>(Entity, VelocityAcceleratorComponent);
}

void UVelocityAcceleratorComponentBlueprintLibrary::EmplaceOrReplace_VelocityAcceleratorComponent(UObject* WorldContextObject, const int32 EntityId, const FVelocityAcceleratorComponent& VelocityAcceleratorComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FVelocityAcceleratorComponent>(Entity, VelocityAcceleratorComponent);
}

void UVelocityAcceleratorComponentBlueprintLibrary::Replace_VelocityAcceleratorComponent(UObject* WorldContextObject, const int32 EntityId, const FVelocityAcceleratorComponent& VelocityAcceleratorComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Replace<FVelocityAcceleratorComponent>(Entity, VelocityAcceleratorComponent);
}

bool UVelocityAcceleratorComponentBlueprintLibrary::AllOf_VelocityAcceleratorComponent(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FVelocityAcceleratorComponent>(Entity);
}

UVelocityAcceleratorComponentWrapper* UVelocityAcceleratorComponentBlueprintLibrary::TryGet_VelocityAcceleratorComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);

    if (FVelocityAcceleratorComponent* Ptr = EntityWorld.TryGet<FVelocityAcceleratorComponent>(Entity)) 
    {
        auto* Wrapper = NewObject<UVelocityAcceleratorComponentWrapper>();
        Wrapper->Set(Ptr);
        return Wrapper;
    }
    return nullptr;
}

void UVelocityAcceleratorComponentBlueprintLibrary::Get_VelocityAcceleratorComponent(UObject* WorldContextObject, const int32 EntityId, FVelocityAcceleratorComponent& OutVelocityAcceleratorComponent)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    OutVelocityAcceleratorComponent = EntityWorld.Get<FVelocityAcceleratorComponent>(Entity);
}

void UVelocityAcceleratorComponentBlueprintLibrary::Remove_VelocityAcceleratorComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FVelocityAcceleratorComponent>(Entity);
}

void UVelocityAcceleratorComponentBlueprintLibrary::Erase_VelocityAcceleratorComponent(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FVelocityAcceleratorComponent>(Entity);
}

int32 UVelocityAcceleratorComponentBlueprintLibrary::MetaType_VelocityAcceleratorComponent(UObject* WorldContextObject)
{
    return entt::resolve<FVelocityAcceleratorComponent>().id();
}
