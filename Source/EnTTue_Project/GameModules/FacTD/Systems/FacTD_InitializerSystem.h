// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <EnTTue/Systems/System.h>
#include "FacTD_InitializerSystem.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ENTTUE_PROJECT_API UFacTD_InitializerSystem : public USystem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* DefaultGridMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UMaterialInterface*> DefaultGridMaterials;

protected:
	virtual void Init(AActor* ActorRoot, FEntityWorld& World) override;
	virtual void Tick(AActor* ActorRoot, FEntityWorld& World, float DeltaTime) override;
};
