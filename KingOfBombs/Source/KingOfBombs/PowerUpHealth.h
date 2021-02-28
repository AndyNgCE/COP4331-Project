// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KBPlayer.h"
#include "PowerUp.h"
#include "PowerUpHealth.generated.h"

/**
 * 
 */
UCLASS()
class KINGOFBOMBS_API APowerUpHealth : public APowerUp
{
	GENERATED_BODY()

public:
	APowerUpHealth();

	void OnPick(AKBPlayer* target) override;
};
