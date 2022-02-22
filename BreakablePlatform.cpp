// Fill out your copyright notice in the Description page of Project Settings.


#include "BreakablePlatform.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

void ABreakablePlatform::ActivateBehaviour()
{
	if (bIsActivatable)
	{
		Super::ActivateBehaviour();

		if (bIsBreakable)
		{
			GetWorldTimerManager().SetTimer(PlatformTimerHandle, this, &ABreakablePlatform::BreakPlatform, BreakDelay, false, -1.f);
		}
	}
}

void ABreakablePlatform::DeactivateBehaviour()
{
	if (bIsActivatable)
	{
		Super::DeactivateBehaviour();
	}
}

void ABreakablePlatform::BreakPlatform()
{
	if (bIsBreakable)
	{
		CollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		SetActorHiddenInGame(true);
		GetWorldTimerManager().SetTimer(PlatformTimerHandle, this, &ABreakablePlatform::ReformPlatform, ReformDelay, false, -1.f);
	}
}

void ABreakablePlatform::ReformPlatform()
{
	if (bIsReformable)
	{
		CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		StaticMesh->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
		StaticMesh->SetCollisionProfileName("BlockAll");
		SetActorHiddenInGame(false);
	}
}