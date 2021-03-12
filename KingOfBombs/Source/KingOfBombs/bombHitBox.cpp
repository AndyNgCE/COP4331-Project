// Fill out your copyright notice in the Description page of Project Settings.


#include "bombHitBox.h"

// Sets default values
AbombHitBox::AbombHitBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BlastRadius = 50 + (50 * 1);
}

// Called when the game starts or when spawned
void AbombHitBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AbombHitBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


