// Fill out your copyright notice in the Description page of Project Settings.


#include "BreakableBlock.h"

ABreakableBlock::ABreakableBlock() {

	int health = 1;
}


void ABreakableBlock::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != nullptr))
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString("Box health is 1"));
	}

}
