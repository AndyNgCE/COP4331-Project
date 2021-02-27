// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpBombUp.h"

APowerUpBombUp::APowerUpBombUp()
{

}

void APowerUpBombUp::OnPick()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Purple, FString(TEXT("More Explosions!")));
}
