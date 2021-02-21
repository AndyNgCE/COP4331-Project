// Fill out your copyright notice in the Description page of Project Settings.


#include "Make_Block.h"
#include "Components/BoxComponent.h"

// Sets default values
AMake_Block::AMake_Block()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionMesh = CreateDefaultSubobject<UBoxComponent>(FName("Collision Mesh"));

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

}

void AMake_Block::DestoryComponent()
{

}

