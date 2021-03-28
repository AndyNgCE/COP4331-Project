// Fill out your copyright notice in the Description page of Project Settings.



#include "BreakableBlock.h"
#include "PowerUpHealth.h"
#include "PowerUpFirepower.h"
#include "PowerUpBombUp.h"
#include "PowerUpMovement.h"
#include "DamageHazzard.h"
#include "SlowDownHazzard.h"
#include "FreezeHazzard.h"

ABreakableBlock::ABreakableBlock()
{
	health = 100;
	ConstructorHelpers::FObjectFinder<UClass>ItemBlueprint(TEXT("Blueprint'/Game/Blueprints/Health.Health_C'"));
	ConstructorHelpers::FObjectFinder<UClass>ItemBlueprintMovement(TEXT("Blueprint'/Game/Blueprints/Movement.Movement_C'"));
	ConstructorHelpers::FObjectFinder<UClass>ItemBlueprintInventory(TEXT("Blueprint'/Game/Blueprints/InventoryUp.InventoryUp_C'"));
	ConstructorHelpers::FObjectFinder<UClass>ItemBlueprintBlast(TEXT("Blueprint'/Game/Blueprints/BlastIncrease.BlastIncrease_C'"));

	ConstructorHelpers::FObjectFinder<UClass>ItemBlueprintDamageH(TEXT("Blueprint'/Game/Blueprints/MyDamageHazzard.MyDamageHazzard_C'"));
	ConstructorHelpers::FObjectFinder<UClass>ItemBlueprintFreezeH(TEXT("Blueprint'/Game/Blueprints/MyFreezeHazzard.MyFreezeHazzard_C'"));
	ConstructorHelpers::FObjectFinder<UClass>ItemBlueprintSlowDownH(TEXT("Blueprint'/Game/Blueprints/MySlowDownHazzard.MySlowDownHazzard_C'"));

	// Power-Up blueprints call
	if (ItemBlueprint.Object)
	{
		MyItemBlueprint = (UClass*)ItemBlueprint.Object;
	}
	if (ItemBlueprintMovement.Object)
	{
		MyItemBlueprintMovement = (UClass*)ItemBlueprintMovement.Object;
	}
	if (ItemBlueprintInventory.Object)
	{
		MyItemBlueprintInventory = (UClass*)ItemBlueprintInventory.Object;
	}
	if (ItemBlueprintBlast.Object)
	{
		MyItemBlueprintBlast = (UClass*)ItemBlueprintBlast.Object;
	}

	// Hazzard blueprints call
	if (ItemBlueprintDamageH.Object)
	{
		MyItemBlueprintDamageH = (UClass*)ItemBlueprintDamageH.Object;
	}
	if (ItemBlueprintFreezeH.Object)
	{
		MyItemBlueprintFreezeH = (UClass*)ItemBlueprintFreezeH.Object;
	}
	if (ItemBlueprintSlowDownH.Object)
	{
		MyItemBlueprintSlowDownH = (UClass*)ItemBlueprintSlowDownH.Object;
	}
}

void ABreakableBlock::TakeDamage(int Damage)
{
	
	health -= Damage;
	if (health <= 0)
	{
		int rand2 = FMath::RandRange(0, 3);
		int rand = FMath::RandRange(0, 7);
		FVector location = this->GetActorLocation();
		location.Set(location.X, location.Y, location.Z-90);
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
				AHazzard* cat = GetWorld()->SpawnActor<ADamageHazzard>(MyItemBlueprintDamageH, location, this->GetActorRotation());
				//GetWorld()->SpawnActor<ADamageHazzard>(ADamageHazzard::StaticClass(), this->GetActorLocation(), this->GetActorRotation());
			}
			else if (rand == 5)
			{
				AHazzard* cat = GetWorld()->SpawnActor<ASlowDownHazzard>(MyItemBlueprintSlowDownH, location, this->GetActorRotation());
				//GetWorld()->SpawnActor<ASlowDownHazzard>(ASlowDownHazzard::StaticClass(), this->GetActorLocation(), this->GetActorRotation());
			}
			else if (rand == 6)
			{
				AHazzard* cat = GetWorld()->SpawnActor<AFreezeHazzard>(MyItemBlueprintFreezeH, location, this->GetActorRotation());
			}
		}
		

		Destroy();
	}

}
