// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomb.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "bombHitBox.h"

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

	// Attaches a static mesh for materials to the sphere component called Collisonbox
	BombMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BombMesh"));
	BombMesh->SetupAttachment(RootComponent);
	BombMesh->SetCollisionProfileName(TEXT("Actor"));
	BombMesh->SetCollisionEnabled(ECollisionEnabled::Type::QueryAndPhysics);
	BombMesh->SetSimulatePhysics(true);
	

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

	detonationCounter += DeltaTime;

	if (detonationCounter >= detonationTime) 
	{
		Explosion();
	}


}

void ABomb::Explosion()
{
	FVector Location = this->GetActorLocation();
	this->SetActorEnableCollision(false);
	BombMesh->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
	BombMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	AbombHitBox* hitbox = GetWorld()->SpawnActor<AbombHitBox>(AbombHitBox::StaticClass(), Location, this->GetActorRotation());

	Destroy();

}
