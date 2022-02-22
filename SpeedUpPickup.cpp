// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedUpPickup.h"
#include "PickupRunnerCharacter.h"

void ASpeedUpPickup::InteractWithPlayer()
{
	PlayerCharacter->SpeedUpBehaviour();

	Super::InteractWithPlayer();
}

void ASpeedUpPickup::RespawnableBehaviour()
{
	PlayerCharacter->RevertSpeedUpBehaviour();
	Super::RespawnableBehaviour();
}