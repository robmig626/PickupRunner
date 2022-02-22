// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RespawnablePickup.h"
#include "SpeedUpPickup.generated.h"

/**
 * 
 */
UCLASS()
class PICKUPRUNNER_API ASpeedUpPickup : public ARespawnablePickup
{
	GENERATED_BODY()

public:
	virtual void InteractWithPlayer() override;
	virtual void RespawnableBehaviour();
};
