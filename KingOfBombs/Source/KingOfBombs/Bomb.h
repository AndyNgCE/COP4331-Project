// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include <KingOfBombs/bombHitBox.h>
#include "Bomb.generated.h"


UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class KINGOFBOMBS_API ABomb : public AActor
{
	GENERATED_BODY()


public:	
	// Sets default values for this component's properties
	ABomb();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Explosion();

	//Initial Bomb Stats
	int bombSize = 1;
	float radius = 50.0f;
	float detonationTime = 3.0;
	FString bombType = "default";

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AbombHitBox> BombHitBox;

	UParticleSystem* ExplosionEffect;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
		class USphereComponent* Collision;

	void generateHitBox();
};
