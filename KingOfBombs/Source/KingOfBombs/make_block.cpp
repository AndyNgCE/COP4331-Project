// Fill out your copyright notice in the Description page of Project Settings.


#include "Make_Block.h"
#include "bombHitBox.h"
#include "Bomb.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
// Sets default values
AMake_Block::AMake_Block()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	CollisionMesh = CreateDefaultSubobject<UBoxComponent>(FName("Collision Mesh"));
	CollisionMesh->SetBoxExtent(FVector(32.0F, 32.0F, 32.0F));
	SetRootComponent(CollisionMesh);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

//	CollisionMesh->OnComponentBeginOverlap.AddDynamic(this, &AMake_Block::OnOverlapBegin);

}


// Called when the game starts or when spawned
void AMake_Block::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMake_Block::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*if (health == 0)
	{
		Destroy();
	}*/
}

/*void AMake_Block::KillBlock()
{
	health--;
}*/

/*void AMake_Block::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AbombHitBox * hitter = Cast<AbombHitBox>(OtherActor);
	ABomb * ball = Cast<ABomb>(OtherActor);
	if (hitter)
	{
		//if(health > 0)
		//{
			KillBlock();
			// Test for destroying blocks -NEEDS TO BE REMOVED LATER-
			Destroy();
		//}
	}
}*/
