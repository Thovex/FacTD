#pragma once

#include "EnTTue/Include.h"

#include "GameFramework/Actor.h"

#include "GameModule.generated.h"

UCLASS(BlueprintType, Blueprintable)
class AGameModule : public AActor {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<USystem>> Systems;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void InitGame();
	void InitGame_Implementation() {}
};

