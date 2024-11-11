$IncludePath$

#include "EnTTue/Utils/EntityUtil.h"

void U$TypeName$BlueprintLibrary::Emplace_$TypeName$(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<F$TypeName$>(Entity);
}

void U$TypeName$BlueprintLibrary::EmplaceOrReplace_$TypeName$(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<F$TypeName$>(Entity);
}

bool U$TypeName$BlueprintLibrary::AllOf_$TypeName$(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<F$TypeName$>(Entity);
}

void U$TypeName$BlueprintLibrary::Remove_$TypeName$(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<F$TypeName$>(Entity);
}

void U$TypeName$BlueprintLibrary::Erase_$TypeName$(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<F$TypeName$>(Entity);
}

int32 U$TypeName$BlueprintLibrary::MetaType_$TypeName$(UObject* WorldContextObject)
{
    return entt::resolve<F$TypeName$>().id();
}
