// Fill out your copyright notice in the Description page of Project Settings.


#include "GhostBomb.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

AGhostBomb::AGhostBomb()
{
	ConstructorHelpers::FObjectFinder<UParticleSystem> FX(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	ExplosionVFX = FX.Object;
}

void AGhostBomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	detonationCounter += DeltaTime;

	if (detonationCounter >= detonationTime)
	{
		FakeExplosion();
	}
}

void AGhostBomb::FakeExplosion()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionVFX, this->GetActorLocation(), this->GetActorRotation(), FVector(3, 3, 3));
	Destroy();
}
