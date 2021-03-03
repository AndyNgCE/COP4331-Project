// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpMovement.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
APowerUpMovement::APowerUpMovement()
{
	Duration = 5;
}


void APowerUpMovement::OnPick(AKBPlayer* target)
{
	if (target != nullptr)
	{
		// Increase speed
		target->MovementSpeed = target->MovementSpeed + 1400;
		target->GetCharacterMovement()->MaxWalkSpeed = target->MovementSpeed;
		target->GetCharacterMovement()->JumpZVelocity= 1400;
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString(TEXT("Movement Speed Up")));
	}
}
