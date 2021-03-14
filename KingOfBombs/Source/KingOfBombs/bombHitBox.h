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
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(VisibleAnywhere)
		class USphereComponent* Collisionbox;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Mesh;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//Bomb Explosion Radius
	//Is set to change when spawned
	float BlastRadius;
	float LingerTime = 1.f;

};
