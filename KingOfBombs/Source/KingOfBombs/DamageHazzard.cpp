// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageHazzard.h"

void ADamageHazzard::AffectPlayer(class AKBPlayer* OtherActor)
{
	OtherActor->Health = OtherActor->Health - 25;
}