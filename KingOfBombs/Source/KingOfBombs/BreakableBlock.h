// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "make_block.h"
#include "BreakableBlock.generated.h"

/**
 * 
 */
UCLASS()
class KINGOFBOMBS_API ABreakableBlock : public AMake_Block
{
	GENERATED_BODY()
public:
	ABreakableBlock();

	void TakeDamage(int Damage);
	// Health item
	TSubclassOf<class APowerUp> MyItemBlueprint;
	// Movement item
	TSubclassOf<class APowerUp> MyItemBlueprintMovement;
	// Inventory item
	TSubclassOf<class APowerUp> MyItemBlueprintInventory;
	// Blast item
	TSubclassOf<class APowerUp> MyItemBlueprintBlast;
};
