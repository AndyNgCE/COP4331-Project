// Fill out your copyright notice in the Description page of Project Settings.


#include "SlowDownHazzard.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

void ASlowDownHazzard::AffectPlayer(AKBPlayer* OtherActor)
{
	if (OtherActor != nullptr)
	{
		isSlow = 1;
		// Decrease speed
		OtherActor->MovementSpeed -= 150;
		OtherActor->GetCharacterMovement()->MaxWalkSpeed = OtherActor->MovementSpeed;
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString(TEXT("slowed")));
	}
}

void ASlowDownHazzard::AffectPlayerEnd(AKBPlayer* OtherActor)
{
	if (OtherActor != nullptr)
	{
		// Increase speed
		OtherActor->MovementSpeed += 150;
		OtherActor->GetCharacterMovement()->MaxWalkSpeed = OtherActor->MovementSpeed;
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString(TEXT("speed restored")));
	}
}