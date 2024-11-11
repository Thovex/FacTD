#include "Generated_UAntiBoidTagBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

void UAntiBoidTagBlueprintLibrary::Emplace_AntiBoidTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FAntiBoidTag>(Entity);
}

void UAntiBoidTagBlueprintLibrary::EmplaceOrReplace_AntiBoidTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FAntiBoidTag>(Entity);
}

bool UAntiBoidTagBlueprintLibrary::AllOf_AntiBoidTag(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FAntiBoidTag>(Entity);
}

void UAntiBoidTagBlueprintLibrary::Remove_AntiBoidTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FAntiBoidTag>(Entity);
}

void UAntiBoidTagBlueprintLibrary::Erase_AntiBoidTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FAntiBoidTag>(Entity);
}

int32 UAntiBoidTagBlueprintLibrary::MetaType_AntiBoidTag(UObject* WorldContextObject)
{
    return entt::resolve<FAntiBoidTag>().id();
}
