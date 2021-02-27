// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PowerUp.h"
#include "PowerUpFirepower.generated.h"

/**
 * 
 */
UCLASS()
class KINGOFBOMBS_API APowerUpFirepower : public APowerUp
{
	GENERATED_BODY()

public:
	APowerUpFirepower();
	
	void OnPick() override;
};
