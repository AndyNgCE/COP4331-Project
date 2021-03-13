// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpFirepower.h"

APowerUpFirepower::APowerUpFirepower()
{
	Duration = 10;
}

void APowerUpFirepower::OnPick(AKBPlayer* target)
{
	if (target != nullptr)
	{
		// Disables collision components
		SetActorEnableCollision(false);
		SetActorHiddenInGame(true);
		// Increase damage range; will require access to bomb.h?
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString(TEXT("Bigger Explosions!")));
		// Place holder destroy until work stat affects are implemented
		Destroy();
		// SetActorTickEnabled(false);
	}
}