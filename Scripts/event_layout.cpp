$IncludePath$

#include <EnTTue/Utils/EventUtil.h>
#include <EnTTue/Utils/EntityUtil.h>

// Copyright Jesse van Vliet (2024 - AND BEYOND!)


int32 U$TypeName$BlueprintLibrary::MetaType_$TypeName$(UObject* WorldContextObject)
{
    return entt::resolve<F$TypeName$>().id();
}

void U$TypeName$BlueprintLibrary::OnEvent_$TypeName$(UObject* WorldContextObject, TArray<F$TypeName$>& $TypeName$)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const auto View = EntityWorld.OnEvent<F$TypeName$>();

    $TypeName$.Empty();
    $TypeName$.Reserve(View.size());
    
    for (auto&& [_, Event] : View.each())
    {
       $TypeName$.Add(Event);
    }
}

void U$TypeName$BlueprintLibrary::OnEvent_Targeted_$TypeName$(UObject* WorldContextObject, TArray<F$TypeName$WithTarget>& $TypeName$)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const auto View = EntityWorld.OnEvent<F$TypeName$, FEventTarget>();
    
    $TypeName$.Empty();
    $TypeName$.Reserve(View.size_hint());
    
    for (auto&& [_, Event, Targets] : View.each())
    {
       $TypeName$.Add({Event, Targets});
    }
}

void U$TypeName$BlueprintLibrary::OnEvent_TargetedTo_$TypeName$(UObject* WorldContextObject, int32 TargetEntity, TArray<F$TypeName$WithTarget>& $TypeName$)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    const auto View = EntityWorld.OnEvent<F$TypeName$, FEventTarget>();
    
    $TypeName$.Empty();
    $TypeName$.Reserve(View.size_hint());
    
    for (auto&& [_, Event, Targets] : View.each())
    {
        if (Targets.Actor == TargetEntity)
        {
            $TypeName$.Add({Event, Targets});
        }
    }
}


void U$TypeName$BlueprintLibrary::Emit_$TypeName$(UObject* WorldContextObject, const F$TypeName$& $TypeName$)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    EntityWorld.Emit($TypeName$);
}

void U$TypeName$BlueprintLibrary::Emit_Targeted_$TypeName$(UObject* WorldContextObject, const F$TypeName$& $TypeName$, const FEventTarget& Target)
{
    FEntityWorld& EntityWorld = EntityUtil::GetEntityWorld(WorldContextObject);
    EntityWorld.Emit($TypeName$, Target);
}



