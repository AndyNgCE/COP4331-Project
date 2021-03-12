// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "KBPlayer.h"
#include "GameFramework/Actor.h"
#include "Hazzard.generated.h"

UCLASS()
class KINGOFBOMBS_API AHazzard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHazzard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* mesh;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* mesh2;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* CollisionMesh = nullptr;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* CollisionMesh2 = nullptr;

	UFUNCTION()
		virtual void AffectPlayer(AKBPlayer* OtherActor);

	UFUNCTION()
		virtual void AffectPlayerEnd(AKBPlayer* OtherActor);

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
