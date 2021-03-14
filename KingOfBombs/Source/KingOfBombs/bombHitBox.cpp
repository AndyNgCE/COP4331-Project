// Fill out your copyright notice in the Description page of Project Settings.


#include "bombHitBox.h"
#include "KBPlayer.h"
#include "make_block.h"
#include "KingOfBombsCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"

// Sets default values
AbombHitBox::AbombHitBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collisionbox = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	Collisionbox->InitSphereRadius(BlastRadius);
	Collisionbox->SetCollisionProfileName("Trigger");
	RootComponent = Collisionbox;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
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
	
	LingerTime -= DeltaTime;
	if (LingerTime <= 0) {
		Destroy();
	}

}

void AbombHitBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Two Points Needed, the center of the explosion, and the actor within the blast radius
	FVector OriginLocation, ActorLocation;
	OriginLocation = this->GetTargetLocation();
	ActorLocation = OtherActor->GetTargetLocation();

	AKingOfBombsCharacter* loser = Cast<AKingOfBombsCharacter>(OtherActor);
	AMake_Block* block = Cast<AMake_Block>(OtherActor);

	FHitResult Casualty = SweepResult;

	bool actorInTheWay = GetWorld()->LineTraceSingleByObjectType(Casualty, OriginLocation, ActorLocation, ECC_WorldStatic, BlastRadius);
	
	if (actorInTheWay) {
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

}


