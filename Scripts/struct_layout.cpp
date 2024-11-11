$IncludePath$

#include "EnTTue/Utils/EntityUtil.h"

// Copyright Jesse van Vliet (2024 - AND BEYOND!)

void U$TypeName$BlueprintLibrary::Emplace_$TypeName$(UObject* WorldContextObject, const int32 EntityId, const F$TypeName$& $TypeName$)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<F$TypeName$>(Entity, $TypeName$);
}

void U$TypeName$BlueprintLibrary::EmplaceOrReplace_$TypeName$(UObject* WorldContextObject, const int32 EntityId, const F$TypeName$& $TypeName$)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<F$TypeName$>(Entity, $TypeName$);
}

void U$TypeName$BlueprintLibrary::Replace_$TypeName$(UObject* WorldContextObject, const int32 EntityId, const F$TypeName$& $TypeName$)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Replace<F$TypeName$>(Entity, $TypeName$);
}

bool U$TypeName$BlueprintLibrary::AllOf_$TypeName$(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<F$TypeName$>(Entity);
}

U$TypeName$Wrapper* U$TypeName$BlueprintLibrary::TryGet_$TypeName$(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);

    if (F$TypeName$* Ptr = EntityWorld.TryGet<F$TypeName$>(Entity)) 
    {
        auto* Wrapper = NewObject<U$TypeName$Wrapper>();
        Wrapper->Set(Ptr);
        return Wrapper;
    }
    return nullptr;
}

void U$TypeName$BlueprintLibrary::Get_$TypeName$(UObject* WorldContextObject, const int32 EntityId, F$TypeName$& Out$TypeName$)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    Out$TypeName$ = EntityWorld.Get<F$TypeName$>(Entity);
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
