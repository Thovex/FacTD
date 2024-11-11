#include "Generated_UDrawDebugTagBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

void UDrawDebugTagBlueprintLibrary::Emplace_DrawDebugTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FDrawDebugTag>(Entity);
}

void UDrawDebugTagBlueprintLibrary::EmplaceOrReplace_DrawDebugTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FDrawDebugTag>(Entity);
}

bool UDrawDebugTagBlueprintLibrary::AllOf_DrawDebugTag(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FDrawDebugTag>(Entity);
}

void UDrawDebugTagBlueprintLibrary::Remove_DrawDebugTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FDrawDebugTag>(Entity);
}

void UDrawDebugTagBlueprintLibrary::Erase_DrawDebugTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FDrawDebugTag>(Entity);
}

int32 UDrawDebugTagBlueprintLibrary::MetaType_DrawDebugTag(UObject* WorldContextObject)
{
    return entt::resolve<FDrawDebugTag>().id();
}
