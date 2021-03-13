// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpBombUp.h"

APowerUpBombUp::APowerUpBombUp()
{
	Duration = -1;
}

void APowerUpBombUp::OnPick(AKBPlayer* target)
{
	if (target != nullptr)
	{
		// Increase inventory
		target->NumBombs++;
		// Disables collision components
		SetActorEnableCollision(false);
		SetActorHiddenInGame(true);
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Purple, FString(TEXT("More Explosions!")));
		Destroy();
	}
}
