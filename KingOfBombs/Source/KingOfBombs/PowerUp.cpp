// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUp.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"

// Sets default values
APowerUp::APowerUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PowerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	// Collision 
	Collisionbox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	Collisionbox->SetBoxExtent(FVector(32.f, 32.f, 32.f));
	Collisionbox->SetCollisionProfileName("Trigger");
	//RootComponent = CollisionBox;

	//Collisionbox->OnComponentBeginOverlap.AddDynamic(this, &APowerUp::OnOverlapBegin);
	//Collisionbox->OnComponentEndOverlap.AddDynamic(this, &APowerUp::OnOverlapEnd);
}

// Called when the game starts or when spawned
void APowerUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APowerUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APowerUp::OnOverlapBegin(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "Power-Up Grabbed");
}

void APowerUp::OnOverlapEnd(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, "Effect Applied");
}

