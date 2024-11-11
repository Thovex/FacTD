#include "Generated_UBakedAnimationsTagBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

void UBakedAnimationsTagBlueprintLibrary::Emplace_BakedAnimationsTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FBakedAnimationsTag>(Entity);
}

void UBakedAnimationsTagBlueprintLibrary::EmplaceOrReplace_BakedAnimationsTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FBakedAnimationsTag>(Entity);
}

bool UBakedAnimationsTagBlueprintLibrary::AllOf_BakedAnimationsTag(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FBakedAnimationsTag>(Entity);
}

void UBakedAnimationsTagBlueprintLibrary::Remove_BakedAnimationsTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FBakedAnimationsTag>(Entity);
}

void UBakedAnimationsTagBlueprintLibrary::Erase_BakedAnimationsTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FBakedAnimationsTag>(Entity);
}

int32 UBakedAnimationsTagBlueprintLibrary::MetaType_BakedAnimationsTag(UObject* WorldContextObject)
{
    return entt::resolve<FBakedAnimationsTag>().id();
}
