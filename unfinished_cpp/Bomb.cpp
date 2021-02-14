// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomb.h"
#include <string>

// Sets default values for this component's properties
UBomb::UBomb()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	int bombSize = 1;
	int bombDamage = 1;
	string bombType = "default";
	// ...
}


// Called when the game starts
void UBomb::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBomb::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

