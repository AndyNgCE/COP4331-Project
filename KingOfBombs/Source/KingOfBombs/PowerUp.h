// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KBPlayer.h"
#include "GameFramework/Actor.h"
#include "PowerUp.generated.h"

UCLASS()
class KINGOFBOMBS_API APowerUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Sets static mesh for power-ups
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
		class USphereComponent* Collisionbox;

	// Set of variables used in the rotation of the Power-Ups
	UPROPERTY(EditAnywhere, Category = "Movement")
		float Pitch;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float Yaw;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float Roll;

	virtual void OnPick(AKBPlayer* target);

	// Set generic variable like hitbox size and inventory flags
	float Radius = 53.0f;
	bool Equipped = false;
	// Duration of effect - debatable if effects should be permanant or not
	float Duration;
	AKBPlayer* reset;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
