// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomb.h"

// Sets default values for this component's properties
ABomb::ABomb()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryActorTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void ABomb::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
// 30 frames per second
void ABomb::Tick(float DeltaTime)
{
	bool timer = false;
	if (DeltaTime == 60) {
		timer = true;
	}

	if (timer == true) {
		Destroy();
	}
	Super::Tick(DeltaTime);
	
	
}