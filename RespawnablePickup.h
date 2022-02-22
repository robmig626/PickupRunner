// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupBase.h"
#include "RespawnablePickup.generated.h"

/**
 * 
 */
UCLASS()
class PICKUPRUNNER_API ARespawnablePickup : public APickupBase
{
	GENERATED_BODY()

public:
	virtual void InteractWithPlayer() override;
	virtual void RespawnableBehaviour();
	void SetbCanRespawn(bool NewCanRespawn);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Pickup")
	bool bCanRespawn = true;

	UPROPERTY(EditAnywhere, Category = "Pickup")
	float RespawnTime = 3.f;

	FTimerHandle PickupTimerHandle;
};
