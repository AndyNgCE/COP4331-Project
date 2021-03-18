// Fill out your copyright notice in the Description page of Project Settings.


#include "bombHitBox.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AbombHitBox::AbombHitBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BlastRadius = 50 + (50 * 1);

	Collisionbox = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	Collisionbox->InitSphereRadius(Radius);
	Collisionbox->SetCollisionProfileName("Trigger");
	RootComponent = Collisionbox;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	// NOTE: Turn off collision physics so players are not stopped midway if they run into hitbox.
}

// Called when the game starts or when spawned
void AbombHitBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AbombHitBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//What happens when caught within explosion radius
//Please check over for errors before reverting code from comment
void AbombHitBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	/*
	//Two Points Needed, the center of the explosion, and the actor within the blast radius
	//Initializing locations
	FVector OriginLocation, ActorLocation;
	OriginLocation = this->GetTargetLocation();
	ActorLocation = OtherActor->GetTargetLocation();

	//Casting to check if actor hit fits one of the two categories
	AKingOfBombsCharacter* loser = Cast<AKingOfBombsCharacter>(OtherActor);
	AMake_Block* block = Cast<AMake_Block>(OtherActor);

	FHitResult Casualty = SweepResult;

	//Actual raytracing part, does need checking
	if (GetWorld()->LineTraceSingleByObjectType(Casualty, OriginLocation, ActorLocation, ECC_WorldStatic, BlastRadius)) { //Should return a bool according to function description
		if (OtherActor == loser || OtherActor == block) {
			//In case of character getting hit
			if (OtherActor == loser) {
				loser->CurrentHealth -= 25;
			}
			//In case a block gets hit
			else {
				block->health -= 1;
			}
		}
	}
	*/
}