// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnTTue/Include.h"

#include "RenderingSystem.generated.h"

class UHierarchicalInstancedStaticMeshComponent;

UCLASS(Blueprintable, BlueprintType)
class ENTTUE_API URenderingSystem : public USystem {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<UStaticMesh*, UHierarchicalInstancedStaticMeshComponent*> HismMeshComponents;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<int32, USkeletalMeshComponent*> SkeletalMeshComponents;

protected:
	virtual void Tick(AActor* ActorRoot, FEntityWorld& World, const float DeltaTime) override;
};
