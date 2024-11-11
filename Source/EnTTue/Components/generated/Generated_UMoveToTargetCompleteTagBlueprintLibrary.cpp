#include "Generated_UMoveToTargetCompleteTagBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

void UMoveToTargetCompleteTagBlueprintLibrary::Emplace_MoveToTargetCompleteTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FMoveToTargetCompleteTag>(Entity);
}

void UMoveToTargetCompleteTagBlueprintLibrary::EmplaceOrReplace_MoveToTargetCompleteTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FMoveToTargetCompleteTag>(Entity);
}

bool UMoveToTargetCompleteTagBlueprintLibrary::AllOf_MoveToTargetCompleteTag(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FMoveToTargetCompleteTag>(Entity);
}

void UMoveToTargetCompleteTagBlueprintLibrary::Remove_MoveToTargetCompleteTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FMoveToTargetCompleteTag>(Entity);
}

void UMoveToTargetCompleteTagBlueprintLibrary::Erase_MoveToTargetCompleteTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FMoveToTargetCompleteTag>(Entity);
}

int32 UMoveToTargetCompleteTagBlueprintLibrary::MetaType_MoveToTargetCompleteTag(UObject* WorldContextObject)
{
    return entt::resolve<FMoveToTargetCompleteTag>().id();
}
