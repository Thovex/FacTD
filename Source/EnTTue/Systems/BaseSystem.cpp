#include "EnTTue/Systems/BaseSystem.h"

#include "EnTTue/Components/EnTTueEvents.h"
#include "EnTTue/Components/BaseComponents.h"
#include "EnTTue/Components/Tags.h"
#include "EnTTue/Components/Timer.h"
#include "EnTTue/Utils/EntityUtil.h"
#include "EnTTue/Utils/EventUtil.h"

void UBaseSystem::Tick(AActor* ActorRoot, FEntityWorld& World, const float DeltaTime) {
	FRegistry& Reg = World.Registry;

	Reg.view<FLifeTimeComponent>(entt::exclude<FDestroyAtEndOfTickTag>).each([&](const EEntity Entity, FLifeTimeComponent& LifeTimeComponent) {
		LifeTimeComponent.LifeTime -= DeltaTime;

		if (LifeTimeComponent.LifeTime <= 0.f) {
			if (LifeTimeComponent.GenericCallback) {
				World.Emit(FGenericEvent(Entity));
			}
			World.EmplaceOrReplace<FDestroyAtEndOfTickTag>(Entity);
		}
	});

	const EEntity TimerSingletonEntity = EntityUtil::GetOrAddSingletonEntity<FTimerSingleton>(World, FName("TimerSingleton"));
	auto& TimerSingleton = World.Get<FTimerSingleton>(TimerSingletonEntity);

	for (int32 i = 0; i < TimerSingleton.ActiveTimers.Num(); )
	{
		auto& Timer = TimerSingleton.ActiveTimers[i];
		Timer.Delay -= DeltaTime;

		if (Timer.Delay <= 0.f)
		{
			// Execute the callback associated with the timer
			Timer.Callback(World);

			if (Timer.Interval == 0.f)
			{
				// Remove the timer if it does not repeat
				TimerSingleton.ActiveTimers.RemoveAt(i);
				continue; // Skip the increment of i to continue with the next timer
			}

			// Reset the timer delay to its interval for repeated execution
			Timer.Delay = Timer.Interval;
		}

		++i; // Only increment if we didn't remove a timer
	}
	
}
