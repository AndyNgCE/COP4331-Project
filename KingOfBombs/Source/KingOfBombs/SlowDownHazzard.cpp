// Fill out your copyright notice in the Description page of Project Settings.


#include "SlowDownHazzard.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

void ASlowDownHazzard::AffectPlayer(AKBPlayer* OtherActor)
{
	if (OtherActor != nullptr)
	{
		// Decrease speed
		OtherActor->GetCharacterMovement()->MaxWalkSpeed /= 3;
	}
}

void ASlowDownHazzard::AffectPlayerEnd(AKBPlayer* OtherActor)
{
	if (OtherActor != nullptr)
	{
		// Increase speed
		OtherActor->GetCharacterMovement()->MaxWalkSpeed *= 3;
	}
}