// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpMovement.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
APowerUpMovement::APowerUpMovement()
{
	Duration = 20;
}

void APowerUpMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*DrawDebugSphere(GetWorld(), GetActorLocation(), Radius, 20, FColor::Red, false, -1, 0, 1);

	// Displays the debug hitbox of the power-up
	DrawDebugSphere(GetWorld(), GetActorLocation(), Radius, 20, FColor::Red, false, -1, 0, 1);

	// Sets the rotation of Power-Up
	FQuat QuatRotation = FQuat(FRotator(Pitch, Yaw, Roll));
	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);*/

	if (Equipped)
	{
		Duration -= 1;
		if (Duration == 0)
		{
			reset->MovementSpeed = reset->MovementSpeed - 1400;
			reset->GetCharacterMovement()->MaxWalkSpeed = reset->MovementSpeed;
			reset->GetCharacterMovement()->JumpZVelocity = 600;
			Equipped = false;
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString(TEXT("Speed Buff Wore Off!")));
		}
	}
}

void APowerUpMovement::OnPick(AKBPlayer* target)
{
	if (target != nullptr)
	{
		// Increase speed
		reset = target;
		target->MovementSpeed = target->MovementSpeed + 1400;
		target->GetCharacterMovement()->MaxWalkSpeed = target->MovementSpeed;
		target->GetCharacterMovement()->JumpZVelocity = 1400;
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString(TEXT("Movement Speed Up")));
	}
}
