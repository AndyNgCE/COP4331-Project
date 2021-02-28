// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Hazzard.h"
#include "DamageHazzard.generated.h"

/**
 * 
 */
UCLASS()
class KINGOFBOMBS_API ADamageHazzard : public AHazzard
{
	GENERATED_BODY()

	void AffectPlayer(class AKBPlayer* OtherActor) override;
	
};
