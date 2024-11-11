#include "Generated_UFacTD_DirectionDirtyTagBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

void UFacTD_DirectionDirtyTagBlueprintLibrary::Emplace_FacTD_DirectionDirtyTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FFacTD_DirectionDirtyTag>(Entity);
}

void UFacTD_DirectionDirtyTagBlueprintLibrary::EmplaceOrReplace_FacTD_DirectionDirtyTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FFacTD_DirectionDirtyTag>(Entity);
}

bool UFacTD_DirectionDirtyTagBlueprintLibrary::AllOf_FacTD_DirectionDirtyTag(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FFacTD_DirectionDirtyTag>(Entity);
}

void UFacTD_DirectionDirtyTagBlueprintLibrary::Remove_FacTD_DirectionDirtyTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FFacTD_DirectionDirtyTag>(Entity);
}

void UFacTD_DirectionDirtyTagBlueprintLibrary::Erase_FacTD_DirectionDirtyTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FFacTD_DirectionDirtyTag>(Entity);
}

int32 UFacTD_DirectionDirtyTagBlueprintLibrary::MetaType_FacTD_DirectionDirtyTag(UObject* WorldContextObject)
{
    return entt::resolve<FFacTD_DirectionDirtyTag>().id();
}
