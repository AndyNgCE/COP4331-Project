// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUp.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"

// Sets default values
APowerUp::APowerUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Radius = 55.0f;

	// Collision box set-up in shape of a sphere
	Collisionbox = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	Collisionbox->InitSphereRadius(Radius);
	Collisionbox->SetCollisionProfileName("Trigger");
	RootComponent = Collisionbox;

	// Attaches a static mesh for materials to the sphere component called Collisonbox
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	Collisionbox->OnComponentBeginOverlap.AddDynamic(this, &APowerUp::OnOverlapBegin);
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
	DrawDebugSphere(GetWorld(), GetActorLocation(), Radius, 20, FColor::Red, false, -1, 0, 1);
}

void APowerUp::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//OtherActor->IsA();
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		OnPick();
		Destroy();
	}
}

void APowerUp::OnPick()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Blue, FString(TEXT("Power Aquired")));
}


