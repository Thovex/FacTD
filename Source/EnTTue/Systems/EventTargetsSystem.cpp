#include "EnTTue/Systems/EventTargetsSystem.h"

#include <EnTTue/Components/EnTTueEvents.h>
#include <EnTTue/Utils/EntityUtil.h>

void UEventTargetsSystem::Tick(AActor* ActorRoot, FEntityWorld& World, const float DeltaTime)
{
	for (auto&& [EventEntity, Event, Targets] : World.OnEachEvent<FEventComponent, FEventTarget>())
	{
		if (!World.Valid(EntityUtil::ToEntity(Targets.Actor)))
		{
			UE_LOG(LogTemp, Warning, TEXT("[UEventTargetsSystem::Tick]>: Removed invalid actor event!"));
			World.Registry.destroy(EventEntity);
			continue;
		}

		auto Iterator = Targets.Targets.CreateIterator();
		while (Iterator)
		{
			if (!World.Valid(EntityUtil::ToEntity(*Iterator)))
			{
				Iterator.RemoveCurrent();
				UE_LOG(LogTemp, Warning, TEXT("[UEventTargetsSystem::Tick]>: Removed invalid target from Event %s"), *Event.EventName.ToString());
			}
			else
			{
				++Iterator;
			}
		}
	}
}
