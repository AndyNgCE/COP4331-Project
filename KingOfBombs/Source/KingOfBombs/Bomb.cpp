// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomb.h"
#include <Runtime/Engine/Private/Components/BoxComponent.cpp>



// Sets default values for this component's properties
ABomb::ABomb()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryActorTick.bCanEverTick = true;
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	UStaticMesh* Asset = MeshAsset.Object;

	Mesh->SetStaticMesh(Asset);
	// ...
}


// Called when the game starts
void ABomb::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frames
void ABomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	detonationTime -= 1;

	if (detonationTime <= 0) {
		Destroy();
		//Explosion();
	}


}

void ABomb::Explosion()
{
	
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorLocation());
	Destroy();

}

void ABomb::generateHitBox()
{
	FVector Location = this->GetActorLocation();
	AbombHitBox* hitbox = GetWorld()->SpawnActor<AbombHitBox>(BombHitBox.Get(), Location, this->GetActorRotation());
}
