// Fill out your copyright notice in the Description page of Project Settings.



#include "BreakableBlock.h"
#include "PowerUpHealth.h"
#include "PowerUpFirepower.h"
#include "PowerUpBombUp.h"
#include "PowerUpMovement.h"
#include "DamageHazzard.h"
#include "SlowDownHazzard.h"
ABreakableBlock::ABreakableBlock()
{
	health = 100;
	ConstructorHelpers::FObjectFinder<UBlueprint>ItemBlueprint(TEXT("Blueprint'/Game/Blueprints/Health.Health'"));
	ConstructorHelpers::FObjectFinder<UBlueprint>ItemBlueprintMovement(TEXT("Blueprint'/Game/Blueprints/Movement.Movement'"));
	ConstructorHelpers::FObjectFinder<UBlueprint>ItemBlueprintInventory(TEXT("Blueprint'/Game/Blueprints/InventoryUp.InventoryUp'"));
	ConstructorHelpers::FObjectFinder<UBlueprint>ItemBlueprintBlast(TEXT("Blueprint'/Game/Blueprints/BlastIncrease.BlastIncrease'"));

	if (ItemBlueprint.Object)
	{
		MyItemBlueprint = (UClass*)ItemBlueprint.Object->GeneratedClass;
	}
	if (ItemBlueprintMovement.Object)
	{
		MyItemBlueprintMovement = (UClass*)ItemBlueprintMovement.Object->GeneratedClass;
	}
	if (ItemBlueprintInventory.Object)
	{
		MyItemBlueprintInventory = (UClass*)ItemBlueprintInventory.Object->GeneratedClass;
	}
	if (ItemBlueprintBlast.Object)
	{
		MyItemBlueprintBlast = (UClass*)ItemBlueprintBlast.Object->GeneratedClass;
	}
}

void ABreakableBlock::TakeDamage(int Damage)
{
	
	health -= Damage;
	if (health <= 0)
	{
		int rand2 = FMath::RandRange(0, 6);
		int rand = FMath::RandRange(0, 3);
		if (rand2 == 0)
		{
			if (rand == 0)
			{
				APowerUp* pup = GetWorld()->SpawnActor<APowerUpHealth>(MyItemBlueprint, this->GetActorLocation(), this->GetActorRotation());
				//GetWorld()->SpawnActor<APowerUpHealth>(APowerUpHealth::StaticClass(), this->GetActorLocation(), this->GetActorRotation());
			}
			else if (rand ==1)
			{
				APowerUp* pup = GetWorld()->SpawnActor<APowerUpFirepower>(MyItemBlueprintBlast, this->GetActorLocation(), this->GetActorRotation());
				//GetWorld()->SpawnActor<APowerUpFirepower>(APowerUpFirepower::StaticClass(), this->GetActorLocation(), this->GetActorRotation());
			}
			else if (rand == 2)
			{
				APowerUp* pup = GetWorld()->SpawnActor<APowerUpBombUp>(MyItemBlueprintInventory, this->GetActorLocation(), this->GetActorRotation());
				//GetWorld()->SpawnActor<APowerUpBombUp>(APowerUpBombUp::StaticClass(), this->GetActorLocation(), this->GetActorRotation());
			}
			else if (rand == 3)
			{
				APowerUp* pup = GetWorld()->SpawnActor<APowerUpMovement>(MyItemBlueprintMovement, this->GetActorLocation(), this->GetActorRotation());
				//GetWorld()->SpawnActor<APowerUpMovement>(APowerUpMovement::StaticClass(), this->GetActorLocation(), this->GetActorRotation());
			}
			else if (rand == 4)
			{
				//APowerUp* pup = GetWorld()->SpawnActor<APowerUpHealth>(MyItemBlueprint, this->GetActorLocation(), this->GetActorRotation());
				GetWorld()->SpawnActor<ADamageHazzard>(ADamageHazzard::StaticClass(), this->GetActorLocation(), this->GetActorRotation());
			}
			else if (rand == 5)
			{
				GetWorld()->SpawnActor<ASlowDownHazzard>(ASlowDownHazzard::StaticClass(), this->GetActorLocation(), this->GetActorRotation());
			}
			else if (rand == 6)
			{
				GetWorld()->SpawnActor<APowerUpHealth>(MyItemBlueprint, this->GetActorLocation(), this->GetActorRotation());
			}
		}
		

		Destroy();
	}

}
