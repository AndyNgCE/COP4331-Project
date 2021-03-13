// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomb.h"


// Sets default values for this component's properties
ABomb::ABomb()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryActorTick.bCanEverTick = true;
	bombSize = 1;
	detonationTime = 3.0;
	seconds = 3.0;
	bombType = "default";
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
	Super::Tick(DeltaTime);

	if (DeltaTime >= detonationTime) {
		Explosion();
	}


}

void ABomb::Explosion()
{
	FVector Location = this->GetActorLocation();
	AbombHitBox* hitbox = GetWorld()->SpawnActor<AbombHitBox>(BombHitBox.Get(), Location, this->GetActorRotation());
	Destroy();

}
