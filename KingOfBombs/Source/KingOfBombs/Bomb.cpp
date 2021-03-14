// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomb.h"
#include "KBPlayer.h"
#include "KingOfBombsCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"


// Sets default values for this component's properties
ABomb::ABomb()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(FName("SphereComponent"));
	Collision->InitSphereRadius(radius);
	Collision->SetCollisionProfileName("Pain");
	RootComponent = Collision;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

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
		Explosion();
	}


}

void ABomb::Explosion()
{
	//Should show an explosion
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorLocation());
	generateHitBox();
	Destroy();

}

//Creates the actor which handles the hitbox
void ABomb::generateHitBox()
{
	FVector Location = this->GetActorLocation();
	AbombHitBox* hitbox;
	hitbox->BlastRadius = radius;
	hitbox = GetWorld()->SpawnActor<AbombHitBox>(BombHitBox.Get(), Location, this->GetActorRotation());
}
