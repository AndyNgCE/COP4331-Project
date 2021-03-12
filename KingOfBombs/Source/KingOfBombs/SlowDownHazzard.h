// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Hazzard.h"
#include "KBPlayer.h"
#include "SlowDownHazzard.generated.h"

/**
 * 
 */
UCLASS()
class KINGOFBOMBS_API ASlowDownHazzard : public AHazzard
{
	GENERATED_BODY()
	
	void AffectPlayer(AKBPlayer* OtherActor) override;

	void AffectPlayerEnd(AKBPlayer* OtherActor) override;

};
