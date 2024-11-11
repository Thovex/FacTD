#include "Generated_UBakedCollisionTagBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

void UBakedCollisionTagBlueprintLibrary::Emplace_BakedCollisionTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FBakedCollisionTag>(Entity);
}

void UBakedCollisionTagBlueprintLibrary::EmplaceOrReplace_BakedCollisionTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FBakedCollisionTag>(Entity);
}

bool UBakedCollisionTagBlueprintLibrary::AllOf_BakedCollisionTag(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FBakedCollisionTag>(Entity);
}

void UBakedCollisionTagBlueprintLibrary::Remove_BakedCollisionTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FBakedCollisionTag>(Entity);
}

void UBakedCollisionTagBlueprintLibrary::Erase_BakedCollisionTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FBakedCollisionTag>(Entity);
}

int32 UBakedCollisionTagBlueprintLibrary::MetaType_BakedCollisionTag(UObject* WorldContextObject)
{
    return entt::resolve<FBakedCollisionTag>().id();
}
