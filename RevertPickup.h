// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RespawnablePickup.h"
#include "RevertPickup.generated.h"

/**
 * 
 */
UCLASS()
class PICKUPRUNNER_API ARevertPickup : public ARespawnablePickup
{
	GENERATED_BODY()
	
	virtual void InteractWithPlayer() override;
	virtual void RespawnableBehaviour();
};
