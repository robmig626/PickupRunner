// Fill out your copyright notice in the Description page of Project Settings.


#include "HighJumpPickup.h"
#include "PickupRunnerCharacter.h"
#include "PickupRunnerGameState.h"
#include "Kismet/GameplayStatics.h"

void AHighJumpPickup::InteractWithPlayer()
{
	PlayerCharacter->IncrementHighJumpCount();
	Super::InteractWithPlayer();
	SetbCanRespawn(false);
}

void AHighJumpPickup::RespawnableBehaviour()
{
	Super::RespawnableBehaviour();
	Cast<APickupRunnerGameState>(UGameplayStatics::GetGameState(GetWorld()))->TestHighJumpPickups();
	//GEngine->AddOnScreenDebugMessage(-1, 0.5, FColor::Green, TEXT("Test for HighJump called!"));
}