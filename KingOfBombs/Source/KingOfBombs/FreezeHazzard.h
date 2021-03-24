// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Hazzard.h"
#include "KBPlayer.h"
#include "FreezeHazzard.generated.h"


UCLASS()
class KINGOFBOMBS_API AFreezeHazzard : public AHazzard
{
	GENERATED_BODY()

	void Tick(float DeltaTime) override;

	void AffectPlayer(AKBPlayer* OtherActor) override;
	void AffectPlayerEnd(AKBPlayer* OtherActor) override;

	float oldSpeed;
	float Duration;
	float froze = 0;
};
