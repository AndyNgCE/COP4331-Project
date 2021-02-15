// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Bomb.generated.h"
#include <string>


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KINGOFBOMBS_API UBomb : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBomb();
	int bombSize = 1;
	int bombDamage = 1;
	string bombType = "default";

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
