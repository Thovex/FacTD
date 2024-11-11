#include "EnTTueMathBlueprintLibrary.h"

float UEnTTueMathBlueprintLibrary::SetScale( float CurrentValue, float OldMinScale, float OldMaxScale, float NewMinScale, float NewMaxScale ) {
	return ( CurrentValue - OldMinScale ) * ( NewMaxScale - NewMinScale ) / ( OldMaxScale - OldMinScale ) + NewMinScale;
}

float UEnTTueMathBlueprintLibrary::SetScalePure( float CurrentValue, float OldMinScale, float OldMaxScale, float NewMinScale, float NewMaxScale ) {
	return ( CurrentValue - OldMinScale ) * ( NewMaxScale - NewMinScale )  / ( OldMaxScale - OldMinScale )  + NewMinScale;
}