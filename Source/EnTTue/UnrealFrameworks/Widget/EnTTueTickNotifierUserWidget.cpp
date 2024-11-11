#include "EnTTueTickNotifierUserWidget.h"

void UEnTTueTickNotifierUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	float CurrentTime = GetWorld()->GetTimeSeconds(); // Get the current game time in seconds
	
	if ((CurrentTime - LastTickTime) > InDeltaTime * 2)
	{	
		// A significant delay means we probably stopped ticking and now resumed
		NativeSync(); // Call the NativeSync event
	}

	// Update last tick time to the current time
	LastTickTime = CurrentTime;
}
