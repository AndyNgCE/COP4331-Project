// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "bombHitBox.generated.h"

UCLASS()
class KINGOFBOMBS_API AbombHitBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AbombHitBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
		class USphereComponent* Collisionbox;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float BlastRadius;
	float Radius = 500.0;
	float LingerTime = 1.f; //Idea is that we should give it a period of time to let the explosion last before the hitbox disappears

	float SpawnTime = 0;
	void SetOwningBomb(class ABomb* Bomb);
	class ABomb* OwningBomb;

	//For the collision of the explosion so people get hurt
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);



	UParticleSystem* ExplosionVFX;
};
