// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bomb.h"
#include "GameFramework/Actor.h"
#include "GhostBomb.generated.h"


/**
 * 
 */
UCLASS()
class KINGOFBOMBS_API AGhostBomb : public ABomb
{
	GENERATED_BODY()
	
public:
	
	AGhostBomb();

	void Tick(float DeltaTime) override;

	void FakeExplosion();

	UParticleSystem* ExplosionVFX;
	
};
