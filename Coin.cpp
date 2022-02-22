// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"
#include "PickupRunnerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "PickupRunnerGameState.h"

void ACoin::InteractWithPlayer()
{
	PlayerCharacter->SetCoinsCollected(PlayerCharacter->GetCoinsCollected() + CoinValue);
	Cast<APickupRunnerGameState>(UGameplayStatics::GetGameState(GetWorld()))->TestCoins();
	AActor::Destroy();
}