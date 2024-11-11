#include "Generated_ULookAtVelocityTagBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

void ULookAtVelocityTagBlueprintLibrary::Emplace_LookAtVelocityTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FLookAtVelocityTag>(Entity);
}

void ULookAtVelocityTagBlueprintLibrary::EmplaceOrReplace_LookAtVelocityTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FLookAtVelocityTag>(Entity);
}

bool ULookAtVelocityTagBlueprintLibrary::AllOf_LookAtVelocityTag(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FLookAtVelocityTag>(Entity);
}

void ULookAtVelocityTagBlueprintLibrary::Remove_LookAtVelocityTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FLookAtVelocityTag>(Entity);
}

void ULookAtVelocityTagBlueprintLibrary::Erase_LookAtVelocityTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FLookAtVelocityTag>(Entity);
}

int32 ULookAtVelocityTagBlueprintLibrary::MetaType_LookAtVelocityTag(UObject* WorldContextObject)
{
    return entt::resolve<FLookAtVelocityTag>().id();
}
