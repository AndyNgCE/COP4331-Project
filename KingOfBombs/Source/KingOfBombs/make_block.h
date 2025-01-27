// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "bombHitBox.h"
#include "Bomb.h"
#include "GameFramework/Actor.h"
#include "Make_Block.generated.h"

UCLASS()
class KINGOFBOMBS_API AMake_Block : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMake_Block();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* CollisionMesh;

	/*UFUNCTION()
		void KillBlock();*/
	
	/*UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);*/

	int health = -1;

	UFUNCTION(BlueprintCallable)
	int GetHealth();
};
