// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupRunnerGameState.h"
#include "Kismet/GameplayStatics.h"
#include "PickupRunnerCharacter.h"
#include "Coin.h"
#include "Goal.h"
#include "HighJumpPickup.h"

void APickupRunnerGameState::BeginPlay()
{
	Super::BeginPlay();
	PlayerCharacter = Cast<APickupRunnerCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACoin::StaticClass(), FoundCoins);
	TotalLevelCoins = FoundCoins.Num();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGoal::StaticClass(), FoundGoals);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHighJumpPickup::StaticClass(), FoundHighJumpPickups);
}

void APickupRunnerGameState::TestCoins()
{
	if (PlayerCharacter->GetCoinsCollected() >= TotalLevelCoins)
	{
		LevelCleared = true;
		//GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, TEXT("Level Cleared!"));
		EnableGoals();
	}
}

bool APickupRunnerGameState::GetLevelCleared() const
{
	return LevelCleared;
}

void APickupRunnerGameState::EnableGoals()
{
	for (AActor* GoalActor : FoundGoals)
	{
		Cast<AGoal>(GoalActor)->ActivateGoal(true);
	}
}

void APickupRunnerGameState::TestHighJumpPickups()
{
	if (PlayerCharacter->GetHighJumpCount() > 0)
	{
		for (AActor* HighJumpPickup : FoundHighJumpPickups)
		{
			Cast<AHighJumpPickup>(HighJumpPickup)->SetbCanRespawn(false);
		}
	}
	else
	{
		for (AActor* HighJumpPickup : FoundHighJumpPickups)
		{
			Cast<AHighJumpPickup>(HighJumpPickup)->SetbCanRespawn(true);
		}
	}
}

int32 APickupRunnerGameState::GetTotalLevelCoins() const
{
	return TotalLevelCoins;
}