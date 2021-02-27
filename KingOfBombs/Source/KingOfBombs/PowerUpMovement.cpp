// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpMovement.h"

APowerUpMovement::APowerUpMovement()
{
	Duration = 5;
}


void APowerUpMovement::OnPick()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString(TEXT("Movement Speed Up")));
}
