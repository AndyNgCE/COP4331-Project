// Fill out your copyright notice in the Description page of Project Settings.


#include "FreezeHazzard.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


void AFreezeHazzard::AffectPlayer(AKBPlayer* OtherActor)
{
	if (OtherActor != nullptr)
	{
		oldSpeed = OtherActor->GetCharacterMovement()->MaxWalkSpeed;
		OtherActor->GetCharacterMovement()->MaxWalkSpeed = 0;
		Duration = 100;
		froze = 1;
	}
}

void AFreezeHazzard::AffectPlayerEnd(AKBPlayer* OtherActor)
{
	if (OtherActor != nullptr)
	{
		OtherActor->GetCharacterMovement()->MaxWalkSpeed = oldSpeed;
		froze = 0;
	}
}

void AFreezeHazzard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(froze == 1){
		Duration -= 1;
		if (Duration <= 0)
		{
				SetActorTickEnabled(false);
				Destroy();
				GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString(TEXT("hazard destroyed")));

		}
	}

}