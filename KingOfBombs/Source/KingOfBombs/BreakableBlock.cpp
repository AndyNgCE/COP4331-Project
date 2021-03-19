// Fill out your copyright notice in the Description page of Project Settings.



#include "BreakableBlock.h"
#include "PowerUpHealth.h"
#include "PowerUpFirepower.h"
#include "PowerUpBombUp.h"
#include "PowerUpMovement.h"
ABreakableBlock::ABreakableBlock()
{
	health = 100;
}

void ABreakableBlock::TakeDamage(int Damage)
{
	health -= Damage;
	if (health <= 0)
	{
		int rand2 = FMath::RandRange(0, 3);
		int rand = FMath::RandRange(0, 3);
		if (rand2 == 0)
		{
			if (rand == 0)
			{
				GetWorld()->SpawnActor<APowerUpHealth>(APowerUpHealth::StaticClass(), this->GetActorLocation(), this->GetActorRotation());
			}
			else if (rand ==1)
			{
				GetWorld()->SpawnActor<APowerUpFirepower>(APowerUpFirepower::StaticClass(), this->GetActorLocation(), this->GetActorRotation());
			}
			else if (rand == 2)
			{
				GetWorld()->SpawnActor<APowerUpBombUp>(APowerUpBombUp::StaticClass(), this->GetActorLocation(), this->GetActorRotation());
			}
			else if (rand == 3)
			{
				GetWorld()->SpawnActor<APowerUpMovement>(APowerUpMovement::StaticClass(), this->GetActorLocation(), this->GetActorRotation());
			}
		}
		

		Destroy();
	}

}
