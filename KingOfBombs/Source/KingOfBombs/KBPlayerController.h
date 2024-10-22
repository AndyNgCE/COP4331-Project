// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "KBPlayer.h"
#include "KBGhost.h"
#include "KBPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class KINGOFBOMBS_API AKBPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	void SpawnAndPossesPlayer();

	void SpawnAndPossesGhost();
};
