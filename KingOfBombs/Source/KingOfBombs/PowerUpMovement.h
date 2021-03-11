// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KBPlayer.h"
#include "PowerUp.h"
#include "PowerUpMovement.generated.h"

/**
 * 
 */
UCLASS()
class KINGOFBOMBS_API APowerUpMovement : public APowerUp
{
	GENERATED_BODY()

public:
	APowerUpMovement();

	void Tick(float DeltaTime) override;
	
	void OnPick(AKBPlayer* target) override;
};
