// Fill out your copyright notice in the Description page of Project Settings.


#include "Hazzard.h"
#include "Components/StaticMeshComponent.h"
#include "KingOfBombsCharacter.h"
#include "KBPlayer.h"
#include "Particles/ParticleSystem.h"

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
	CollisionMesh->OnComponentBeginOverlap.AddDynamic(this, &AHazzard::OnOverlapBegin);
	CollisionMesh->OnComponentEndOverlap.AddDynamic(this, &AHazzard::OnOverlapEnd);

	mesh2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("reciever mesh"));
	mesh2->SetRelativeLocation(FVector(720.f, 720.f, 520.f));
	CollisionMesh2 = CreateDefaultSubobject<UBoxComponent>(FName("reciever collision"));
	CollisionMesh2->SetRelativeLocation(FVector(720.f, 720.f, 520.f));
	CollisionMesh2->SetBoxExtent(FVector(32.f, 32.f, 12.f));

	//PartComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("BeamComp"));
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

void AHazzard::AffectPlayer(AKBPlayer* OtherActor)
{

}

void AHazzard::AffectPlayerEnd(AKBPlayer* OtherActor)
{

}

void AHazzard::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AKBPlayer* player = Cast<AKBPlayer>(OtherActor);
	if (player)
	{
		AffectPlayer(player);
	}
}

void AHazzard::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AKBPlayer* player = Cast<AKBPlayer>(OtherActor);
	if (player)
	{
		AffectPlayerEnd(player);
	}
}

