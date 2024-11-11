#include "Generated_UTransformDirtyTagBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

void UTransformDirtyTagBlueprintLibrary::Emplace_TransformDirtyTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FTransformDirtyTag>(Entity);
}

void UTransformDirtyTagBlueprintLibrary::EmplaceOrReplace_TransformDirtyTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FTransformDirtyTag>(Entity);
}

bool UTransformDirtyTagBlueprintLibrary::AllOf_TransformDirtyTag(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FTransformDirtyTag>(Entity);
}

void UTransformDirtyTagBlueprintLibrary::Remove_TransformDirtyTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FTransformDirtyTag>(Entity);
}

void UTransformDirtyTagBlueprintLibrary::Erase_TransformDirtyTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FTransformDirtyTag>(Entity);
}

int32 UTransformDirtyTagBlueprintLibrary::MetaType_TransformDirtyTag(UObject* WorldContextObject)
{
    return entt::resolve<FTransformDirtyTag>().id();
}
