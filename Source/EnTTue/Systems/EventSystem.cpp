#include "EnTTue/Systems/EventSystem.h"

#include "EnTTue/Components/EnTTueEvents.h"
#include "EnTTue/UnrealFrameworks/Widget/EnTTueGameInterface.h"

void UEventSystem::Tick(AActor* ActorRoot, FEntityWorld& World, const float DeltaTime) {

	Super::Tick(ActorRoot, World, DeltaTime);

	World.IncomingEvents = FRegistry {};
	if (World.OutgoingEvents.storage<EEntity>().size() > 0)
	{
		for (auto&& [Entity, Name] : World.OutgoingEvents.view<FEventComponent>().each())
		{
			UE_LOG(LogTemp, Display, TEXT("Processing new event: %s"), *Name.EventName.ToString());
		}

		World.OutgoingEvents.swap(World.IncomingEvents);
	}
}
