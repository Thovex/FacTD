#include "Generated_UDestroyAtEndOfTickTagBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

void UDestroyAtEndOfTickTagBlueprintLibrary::Emplace_DestroyAtEndOfTickTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FDestroyAtEndOfTickTag>(Entity);
}

void UDestroyAtEndOfTickTagBlueprintLibrary::EmplaceOrReplace_DestroyAtEndOfTickTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FDestroyAtEndOfTickTag>(Entity);
}

bool UDestroyAtEndOfTickTagBlueprintLibrary::AllOf_DestroyAtEndOfTickTag(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FDestroyAtEndOfTickTag>(Entity);
}

void UDestroyAtEndOfTickTagBlueprintLibrary::Remove_DestroyAtEndOfTickTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FDestroyAtEndOfTickTag>(Entity);
}

void UDestroyAtEndOfTickTagBlueprintLibrary::Erase_DestroyAtEndOfTickTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FDestroyAtEndOfTickTag>(Entity);
}

int32 UDestroyAtEndOfTickTagBlueprintLibrary::MetaType_DestroyAtEndOfTickTag(UObject* WorldContextObject)
{
    return entt::resolve<FDestroyAtEndOfTickTag>().id();
}
