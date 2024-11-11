// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnTTue/Include.h"

#include "Blueprint/UserWidget.h"

#include "EnTTueDebugPanel.generated.h"


/**
 * 
 */
UCLASS(BlueprintType)
class ENTTUE_API UEnTTueDebugPanel : public UUserWidget
{
	GENERATED_BODY()

public:
	FEntityWorld* World;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 AliveEntityCount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 TotalEntityCount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<int32, FText> EntityData;

protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
};
