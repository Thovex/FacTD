#pragma once

#include <Blueprint/UserWidget.h>

#include "CoreMinimal.h"

#include "EnTTue/Include.h"
#include "EnTTue/Components/EnTTueEvents.h"

#include "EnTTueTickNotifierUserWidget.generated.h"


UCLASS(BlueprintType, Blueprintable, meta = (ShortTooltip = "A UserWidget that notifies the EnTTue system of its tick events"))
class ENTTUE_API UEnTTueTickNotifierUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "EnTTue")
	void NativeSync();
	
protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
	double LastTickTime = 0.0;
};