// Fill out your copyright notice in the Description page of Project Settings.


#include "RespawnablePickup.h"
#include "Components/BoxComponent.h"

void ARespawnablePickup::BeginPlay()
{
	Super::BeginPlay();
}

void ARespawnablePickup::InteractWithPlayer()
{

	//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Yellow, TEXT("Interacted with Respawnable actor"));

	if (bCanRespawn)
	{
		GetWorldTimerManager().SetTimer(PickupTimerHandle, this, &ARespawnablePickup::RespawnableBehaviour, RespawnTime, false, -1.f);
	}
	else
	{
	}
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SetActorHiddenInGame(true);
}

void ARespawnablePickup::RespawnableBehaviour()
{
	if (bCanRespawn)
	{
		APickupBase::CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		SetActorHiddenInGame(false);
	}
	else
	{
		GetWorldTimerManager().SetTimer(PickupTimerHandle, this, &ARespawnablePickup::RespawnableBehaviour, RespawnTime, false, -1.f);
	}
}

void ARespawnablePickup::SetbCanRespawn(bool NewCanRespawn)
{
	bCanRespawn = NewCanRespawn;
}