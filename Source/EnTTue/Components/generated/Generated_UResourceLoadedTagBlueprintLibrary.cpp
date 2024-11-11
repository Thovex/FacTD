#include "Generated_UResourceLoadedTagBlueprintLibrary.h"

#include "EnTTue/Utils/EntityUtil.h"

void UResourceLoadedTagBlueprintLibrary::Emplace_ResourceLoadedTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Emplace<FResourceLoadedTag>(Entity);
}

void UResourceLoadedTagBlueprintLibrary::EmplaceOrReplace_ResourceLoadedTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.EmplaceOrReplace<FResourceLoadedTag>(Entity);
}

bool UResourceLoadedTagBlueprintLibrary::AllOf_ResourceLoadedTag(UObject* WorldContextObject, const int32 EntityId)
{
    const FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    return EntityWorld.AllOf<FResourceLoadedTag>(Entity);
}

void UResourceLoadedTagBlueprintLibrary::Remove_ResourceLoadedTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Remove<FResourceLoadedTag>(Entity);
}

void UResourceLoadedTagBlueprintLibrary::Erase_ResourceLoadedTag(UObject* WorldContextObject, const int32 EntityId)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const EEntity Entity = EntityUtil::ToEntity(EntityId);
    EntityWorld.Erase<FResourceLoadedTag>(Entity);
}

int32 UResourceLoadedTagBlueprintLibrary::MetaType_ResourceLoadedTag(UObject* WorldContextObject)
{
    return entt::resolve<FResourceLoadedTag>().id();
}
