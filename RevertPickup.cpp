// Fill out your copyright notice in the Description page of Project Settings.


#include "RevertPickup.h"
#include "PickupRunnerCharacter.h"

void ARevertPickup::InteractWithPlayer()
{
	Super::InteractWithPlayer();
	PlayerCharacter->RevertBehaviour();
}

void ARevertPickup::RespawnableBehaviour()
{
	Super::RespawnableBehaviour();
}