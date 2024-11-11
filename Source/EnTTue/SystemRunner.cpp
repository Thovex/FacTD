// Fill out your copyright notice in the Description page of Project Settings.

#include "EnTTue/SystemRunner.h"
#include "EnTTue/Systems/System.h"

#include "EnTTue/UnrealFrameworks/EnTTueGameInstance.h"

#include "Engine/World.h"

ASystemRunner::ASystemRunner() {
	PrimaryActorTick.bCanEverTick = true;
}

void ASystemRunner::BeginPlay() {
	Super::BeginPlay();
	
	UEnTTueGameInstance* GameInst = static_cast<UEnTTueGameInstance*>(GetGameInstance());
	World = &GameInst->GetEntityWorld();

	check(World);
	
	GameInst->SystemRunner = this;

	for (TSubclassOf<USystem> SystemClass : PreSystems) {
		USystem* System = NewObject<USystem>(this, SystemClass);
		System->Init(this, *World);
		
		Systems.Add(System);
	}

	for (TSubclassOf<USystem> SystemClass : GameSystems) {
		USystem* System = NewObject<USystem>(this, SystemClass);
		System->Init(this, *World);
		
		Systems.Add(System);
	}

	if (GameModule) {
		LoadedModule = GetWorld()->SpawnActor<AGameModule>(GameModule);

		if (LoadedModule) {
			for (TSubclassOf<USystem> SystemClass : LoadedModule->Systems) {
				USystem* System = NewObject<USystem>(this, SystemClass);
				System->Init(this, *World);
		
				Systems.Add(System);
			}
		} else {
			UE_LOG(LogTemp, Error, TEXT("Failed to load game module!"));
		}
	}

	for (TSubclassOf<USystem> SystemClass : PostSystems) {
		USystem* System = NewObject<USystem>(this, SystemClass);
		System->Init(this, *World);
		
		Systems.Add(System);
	}

	if (LoadedModule) {
		LoadedModule->InitGame();
	}

	InitGame();
}

void ASystemRunner::Tick(const float DeltaTime) {
	Super::Tick(DeltaTime);

	if (!Paused) {
		World->Time.TickIndex++;
		
		for (USystem* System : Systems) {
			System->Tick(this, *World, DeltaTime);
		}
	}
}
void ASystemRunner::InitGame_Implementation() {
}

