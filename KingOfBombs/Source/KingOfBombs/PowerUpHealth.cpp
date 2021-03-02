// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpHealth.h"

APowerUpHealth::APowerUpHealth()
{
	Duration = -1;
}

void APowerUpHealth::OnPick(AKBPlayer* target)
{
	if (target != nullptr)
	{
		// Increase health
		target->CurrentHealth -= 25;
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString(TEXT("Healed One Point of Damage!")));
	}
}