// Fill out your copyright notice in the Description page of Project Settings.


#include "Hazzard.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AHazzard::AHazzard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionMesh = CreateDefaultSubobject<UBoxComponent>(FName("Collision Mesh"));
	CollisionMesh->SetBoxExtent(FVector(32.0F, 32.0F, 32.0F));
	SetRootComponent(CollisionMesh);

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->SetupAttachment(RootComponent);
	//set default size once we know size of blocks the level is made of
}

// Called when the game starts or when spawned
void AHazzard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHazzard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHazzard::AffectPlayer(class AActor* OtherActor)
{

}

void AHazzard::OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		AffectPlayer(OtherActor);
	}
}

