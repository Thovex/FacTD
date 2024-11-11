#include "EnTTueBlueprintLibrary.h"

#include "EnTTue/Utils/EntityBuilderUtil.h"
#include "EnTTue/Utils/EntityUtil.h"

int32 UEnTTueBlueprintLibrary::CreateEmptyEntity(UObject* WorldContextObject)
{
    FEntityWorld& World = EntityUtil::GetEntityWorld(WorldContextObject);
    return EntityUtil::ToInt32(EntityBuilderUtil::CreateEntity(World, NAME_None, World.GetRootEntity(), FTransform::Identity));
}

int32 UEnTTueBlueprintLibrary::CreateNamedEntity(UObject* WorldContextObject, const FName& Name)
{
    FEntityWorld& World = EntityUtil::GetEntityWorld(WorldContextObject);
    return EntityUtil::ToInt32(EntityBuilderUtil::CreateEntity(World, Name, World.GetRootEntity(), FTransform::Identity));
}

int32 UEnTTueBlueprintLibrary::CreateEntity(UObject* WorldContextObject, const FName& Name, const FTransform& Transform)
{
    FEntityWorld& World = EntityUtil::GetEntityWorld(WorldContextObject);
    return EntityUtil::ToInt32(EntityBuilderUtil::CreateEntity(World, Name, World.GetRootEntity(), Transform));
}

int32 UEnTTueBlueprintLibrary::CreateEntityWithParent(UObject* WorldContextObject, const FName& Name, int32 ParentEntityId, const FTransform& Transform)
{
    FEntityWorld& World = EntityUtil::GetEntityWorld(WorldContextObject);
    return EntityUtil::ToInt32(EntityBuilderUtil::CreateEntity(World, Name, EntityUtil::ToEntity(ParentEntityId), Transform));
}

bool UEnTTueBlueprintLibrary::IsValid(UObject* WorldContextObject, int32 EntityId)
{
    return EntityUtil::GetEntityWorld(WorldContextObject).Valid(EntityUtil::ToEntity(EntityId));
}

int32 UEnTTueBlueprintLibrary::FindChildWithComponent(UObject* WorldContextObject, int32 EntityId, UStruct* ComponentType, const bool IncludeRoot)
{
    UE_LOG(LogTemp, Error, TEXT("FindChildWithComponent is not implemented yet"));
    
    return 0;
}
