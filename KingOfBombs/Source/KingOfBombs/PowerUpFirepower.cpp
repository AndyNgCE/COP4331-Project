// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpFirepower.h"

APowerUpFirepower::APowerUpFirepower()
{
	
}

void APowerUpFirepower::OnPick()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString(TEXT("Bigger Explosions!")));
}