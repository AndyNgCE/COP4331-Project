// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUp.h"
#include "KBPlayer.h"
#include "KingOfBombsCharacter.h"
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

	Pitch = 0.f;
	Yaw = -8.f;
	Roll = 0.f;

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

	// Displays the debug hitbox of the power-up
	DrawDebugSphere(GetWorld(), GetActorLocation(), Radius, 20, FColor::Red, false, -1, 0, 1);

	// Sets the rotation of Power-Up
	FQuat QuatRotation = FQuat(FRotator(Pitch, Yaw, Roll));
	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
}

// Remove the Power-Up instance when in contact with player actor
void APowerUp::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Specifying which actor in the scene can trigger the destroy functions
	AKBPlayer* player = Cast<AKBPlayer>(OtherActor);
	AKingOfBombsCharacter* impact = Cast<AKingOfBombsCharacter>(OtherActor);
	if (impact != nullptr) //&& (OtherActor != this) && (OtherComp != nullptr))
	{
		OnPick();
		Destroy();
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Blue, FString(TEXT("Power contact")));
	}
}

// Use to print generic power up message - override to print specialized messages
void APowerUp::OnPick()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Blue, FString(TEXT("Power Aquired")));
}


