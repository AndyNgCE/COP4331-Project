// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageHazzard.h"

void ADamageHazzard::AffectPlayer(AKBPlayer* OtherActor)
{
	OtherActor->CurrentHealth -= 25;
}