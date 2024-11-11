// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// EnTTue
#include "EnTTue/Include.h"
#include "EnTTue/Modules/GameModule.h"

// UE
#include "GameFramework/Actor.h"

#include "SystemRunner.generated.h"


UCLASS(BlueprintType)
class ENTTUE_API ASystemRunner : public AActor {
	GENERATED_BODY()

public:
	ASystemRunner();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void InitGame();

	FEntityWorld* World = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Paused = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<USystem>> PreSystems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<USystem>> GameSystems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<USystem>> PostSystems;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<USystem*> Systems;

	UPROPERTY()
	AGameModule* LoadedModule = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AGameModule> GameModule;
};
