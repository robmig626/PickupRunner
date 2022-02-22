// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal.h"
#include "Kismet/GameplayStatics.h"
#include "PickupRunnerGameState.h"
#include "Components/BoxComponent.h"
#include "PickupRunnerCharacter.h"


void AGoal::BeginPlay()
{
	Super::BeginPlay();
	ActivateGoal(bIsActiveAtLevelStart);
}

void AGoal::InteractWithPlayer()
{
	Super::InteractWithPlayer();
	
	if (PlayerCharacter)
	{
		PlayerCharacter->SetHasReachedGoal(true);
	}

	if (Cast<APickupRunnerGameState>(UGameplayStatics::GetGameState(GetWorld()))->GetLevelCleared())
	{
		UGameplayStatics::OpenLevel(GetWorld(), NextLevel);
	}
}

void AGoal::ActivateGoal(bool NewActive)
{
	if (NewActive)
	{
		SetActorHiddenInGame(false);
		CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}
	else
	{
		SetActorHiddenInGame(true);
		CollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}