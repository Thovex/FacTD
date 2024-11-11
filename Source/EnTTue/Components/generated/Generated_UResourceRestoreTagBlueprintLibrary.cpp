#include "Generated_UResourceRestoreTagBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

void UResourceRestoreTagBlueprintLibrary::Emplace_ResourceRestoreTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FResourceRestoreTag>(Entity);
}

void UResourceRestoreTagBlueprintLibrary::EmplaceOrReplace_ResourceRestoreTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FResourceRestoreTag>(Entity);
}

bool UResourceRestoreTagBlueprintLibrary::AllOf_ResourceRestoreTag(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FResourceRestoreTag>(Entity);
}

void UResourceRestoreTagBlueprintLibrary::Remove_ResourceRestoreTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FResourceRestoreTag>(Entity);
}

void UResourceRestoreTagBlueprintLibrary::Erase_ResourceRestoreTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FResourceRestoreTag>(Entity);
}

int32 UResourceRestoreTagBlueprintLibrary::MetaType_ResourceRestoreTag(UObject* WorldContextObject)
{
    return entt::resolve<FResourceRestoreTag>().id();
}
