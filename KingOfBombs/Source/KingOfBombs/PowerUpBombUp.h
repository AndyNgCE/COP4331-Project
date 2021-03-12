// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KBPlayer.h"
#include "PowerUp.h"
#include "PowerUpBombUp.generated.h"

/**
 * 
 */
UCLASS()
class KINGOFBOMBS_API APowerUpBombUp : public APowerUp
{
	GENERATED_BODY()

public:
	APowerUpBombUp();

	void OnPick(AKBPlayer* target) override;
};
