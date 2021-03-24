// Fill out your copyright notice in the Description page of Project Settings.


#include "bombHitBox.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "KingOfBombsCharacter.h"
#include "make_block.h"
#include "Bomb.h"
#include "BreakableBlock.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AbombHitBox::AbombHitBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collisionbox = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	Collisionbox->InitSphereRadius(Radius);
	Collisionbox->SetCollisionProfileName("OverlapAll");
	Collisionbox->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
	Collisionbox->SetGenerateOverlapEvents(true);
	RootComponent = Collisionbox;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	Collisionbox->OnComponentBeginOverlap.AddDynamic(this, &AbombHitBox::OnOverlapBegin);


	ConstructorHelpers::FObjectFinder<UParticleSystem> FX(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	ExplosionVFX = FX.Object;
	
}


// Called when the game starts or when spawned
void AbombHitBox::BeginPlay()
{
	Super::BeginPlay();
	SpawnTime = GetWorld()->TimeSeconds;

	//GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, "spawning bomb box");
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionVFX, this->GetActorLocation(), this->GetActorRotation(), FVector(3,3,3));
}

// Called every frame
void AbombHitBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UKismetSystemLibrary::DrawDebugSphere(GetWorld(), this->GetActorLocation(), 500);
	if (GetWorld()->TimeSeconds - SpawnTime > .10f)
	{
		Destroy();
	}
}

void AbombHitBox::SetOwningBomb(ABomb* Bomb)
{
	OwningBomb = Bomb;
}

//What happens when caught within explosion radius
//Please check over for errors before reverting code from comment
void AbombHitBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	/*Two Points Needed, the center of the explosion, and the actor within the blast radius
	Initializing locations*/


	FVector OriginLocation, ActorLocation;
	OriginLocation = this->GetTargetLocation();
	ActorLocation = OtherActor->GetTargetLocation();


	FHitResult Casualty;

	//Actual raytracing part, does need checking
	FCollisionObjectQueryParams Params;

	//Params.AddObjectTypesToQuery(ECollisionChannel::ECC_PhysicsBody);
	//Params.AddObjectTypesToQuery(ECollisionChannel::ECC_Visibility);
	//Params.AddObjectTypesToQuery(ECollisionChannel::ECC_MAX);
	Params.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldDynamic);
	Params.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldStatic);
	Params.AddObjectTypesToQuery(ECollisionChannel::ECC_Pawn);

	FCollisionQueryParams QParams;
	QParams.AddIgnoredActor(this);

	//UKismetSystemLibrary::DrawDebugLine(GetWorld(), this->GetActorLocation(), OtherActor->GetActorLocation(), FLinearColor::Red, 1, 10);
	if (GetWorld()->LineTraceSingleByObjectType(Casualty, OriginLocation, ActorLocation, Params, QParams))
	{ //Should return a bool according to function description

		if (Casualty.Actor == OtherActor)
		{
			
			if (OtherActor->IsA<AKingOfBombsCharacter>())
			{
				if (AKingOfBombsCharacter* loser = Cast<AKingOfBombsCharacter>(OtherActor))
				{
					//loser->CurrentHealth -= 25;
					loser->TakeDamage(25);
				}
			}
			else if (OtherActor->IsA<ABreakableBlock>())
			{
				if (ABreakableBlock* block = Cast<ABreakableBlock>(OtherActor))
				{
					block->TakeDamage(25);
				}
			}
		}
		if (OtherActor->IsA<AKingOfBombsCharacter>())
		{
			//GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, Casualty.Actor->GetName());
		}
		
	}
	
}

void AbombHitBox::ChangeRadius(float size)
{
	BlastRadius = size * 100;
	Collisionbox->SetSphereRadius(BlastRadius);
}
