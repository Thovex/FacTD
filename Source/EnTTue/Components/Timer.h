#pragma once

#include <EnTTue/Include.h>

#include "CoreMinimal.h"

#include "Timer.generated.h"

struct FTimerEvent
{
	float Delay = 0.f;
	float Interval = 0.f;
	TFunction<void(FEntityWorld&)> Callback;
};

USTRUCT(Blueprintable)
struct FTimerSingleton
{
	GENERATED_BODY()
	
	TArray<FTimerEvent> ActiveTimers;

	void SetTimer(const float Delay, const TFunction<void(FEntityWorld&)>& Callback, const bool Repeat = false)
	{
		ActiveTimers.Add(FTimerEvent{ Delay, Repeat ? Delay : 0.f, Callback });
	}
};
