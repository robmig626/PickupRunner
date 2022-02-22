// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupBase.h"
#include "Coin.generated.h"

/**
 * 
 */
UCLASS()
class PICKUPRUNNER_API ACoin : public APickupBase
{
	GENERATED_BODY()
	
public:
	virtual void InteractWithPlayer() override;

private:
	UPROPERTY(EditAnywhere)
	int32 CoinValue = 1;
};
