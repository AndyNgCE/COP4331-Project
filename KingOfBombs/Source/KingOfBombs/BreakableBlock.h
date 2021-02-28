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

};
UFUNCTION()
void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);