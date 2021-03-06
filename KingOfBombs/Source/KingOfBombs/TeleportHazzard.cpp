// Fill out your copyright notice in the Description page of Project Settings.


#include "TeleportHazzard.h"

void ATeleportHazzard::AffectPlayer(AKBPlayer* OtherActor)
{
	//get all teleport Actors
	//even numbered teleports send to list+1, odds odds send to list-1
	//dissable onOverlapBegin before teleport
	OtherActor->SetActorLocation(FVector(50.0F, 50.0F, 50.0F));
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString(TEXT("teleport")));
}

void ATeleportHazzard::AffectPlayerEnd(AKBPlayer* OtherActor)
{
	//get all teleport Actors
	//even numbered teleports send to list+1, odds odds send to list-1
	//dissable onOverlapBegin before teleport
	//OtherActor->SetActorLocation(FVector(32.0F, 32.0F, 320.0F));
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString(TEXT("teleport exit")));
}