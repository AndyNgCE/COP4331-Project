// Copyright Epic Games, Inc. All Rights Reserved.

#include "KingOfBombsGameMode.h"
#include "KingOfBombsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AKingOfBombsGameMode::AKingOfBombsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
