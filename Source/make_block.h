// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Make_Block.generated.h"

UCLASS()
class KINGOFBOMBS_API AMake_Block : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMake_Block();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	class UBoxComponent* CollisionMesh = nullptr;

	UFUNCTION()
	void DestoryComponent();
		
};