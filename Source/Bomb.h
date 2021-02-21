// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"


#include "Bomb.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KINGOFBOMBS_API ABomb : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ABomb();
	int bombSize = 1;
	int bombDamage = 1;
	FString bombType = "default";


	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
