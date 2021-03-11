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

	if (Equipped)
	{
		Duration -= 1;
		if (Duration <= 0)
		{
			// Fix player speed after power up ends
			//reset->MovementSpeed -= reset->MovementSpeed - 1400;
			reset->GetCharacterMovement()->MaxWalkSpeed -= 1400;
			//reset->GetCharacterMovement()->JumpZVelocity = 600;
			Equipped = false;
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString(TEXT("Speed Buff Wore Off!")));
			SetActorTickEnabled(false);
			Destroy();
		}
	}

}

void APowerUpMovement::OnPick(AKBPlayer* target)
{
	if (target != nullptr)
	{
		reset = target;
		// Disables collision components
		SetActorEnableCollision(false);
		SetActorHiddenInGame(true);
		// Increase speed
		//target->MovementSpeed += target->MovementSpeed + 1400;
		target->GetCharacterMovement()->MaxWalkSpeed += 1400;
		//target->GetCharacterMovement()->JumpZVelocity = 1400;
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString(TEXT("Movement Speed Up")));
		if (Duration != 20)
		{
			Duration = 20;
		}
	}
}
