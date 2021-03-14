// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include <KingOfBombs/bombHitBox.h>
#include "Bomb.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KINGOFBOMBS_API ABomb : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ABomb();


	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* BombMesh;

	UPROPERTY(VisibleAnywhere)
		class USphereComponent* Collisionbox;

	void Explosion();

	//Initial Bomb Stats
	int bombSize = 1;
	float Radius = 53.0f;
	float seconds = 3.0;
	float detonationTime = 3.0;
	FString bombType = "default";

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AbombHitBox> BombHitBox;
};
