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
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString(TEXT("Bigger Explosions!")));
	}
}