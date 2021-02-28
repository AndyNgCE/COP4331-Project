// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageHazzard.h"

void ADamageHazzard::AffectPlayer(AKBPlayer* OtherActor)
{
	OtherActor->Health = OtherActor->Health - 25;
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::FromInt(OtherActor->Health));
}