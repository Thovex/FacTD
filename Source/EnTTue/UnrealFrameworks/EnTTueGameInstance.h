// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnTTinspector/Include.h"

#include "EnTTueGameInstance.generated.h"

class ASystemRunner;

DECLARE_LOG_CATEGORY_EXTERN(LogECS, Log, All);

UCLASS(BlueprintType)
class ENTTUE_API UEnTTueGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UEnTTueGameInstance(); 

protected:
	UFUNCTION(BlueprintCallable)
	TArray<int32> GetEntities() const;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ASystemRunner* SystemRunner;
	
	FEntityWorld World;
	FEntityWorld& GetEntityWorld();
	
	virtual void RegisterInspectors(TMap<FName, TFunction<TSharedRef<IComponentInspector>(FEntityWorld&, EEntity Entity)>>& RegisteredInspectors);
};
