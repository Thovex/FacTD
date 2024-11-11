#include "Generated_UHiddenInInspectorTagBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

void UHiddenInInspectorTagBlueprintLibrary::Emplace_HiddenInInspectorTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FHiddenInInspectorTag>(Entity);
}

void UHiddenInInspectorTagBlueprintLibrary::EmplaceOrReplace_HiddenInInspectorTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FHiddenInInspectorTag>(Entity);
}

bool UHiddenInInspectorTagBlueprintLibrary::AllOf_HiddenInInspectorTag(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FHiddenInInspectorTag>(Entity);
}

void UHiddenInInspectorTagBlueprintLibrary::Remove_HiddenInInspectorTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FHiddenInInspectorTag>(Entity);
}

void UHiddenInInspectorTagBlueprintLibrary::Erase_HiddenInInspectorTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FHiddenInInspectorTag>(Entity);
}

int32 UHiddenInInspectorTagBlueprintLibrary::MetaType_HiddenInInspectorTag(UObject* WorldContextObject)
{
    return entt::resolve<FHiddenInInspectorTag>().id();
}
