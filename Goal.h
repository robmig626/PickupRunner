// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupBase.h"
#include "Goal.generated.h"

/**
 * 
 */
UCLASS()
class PICKUPRUNNER_API AGoal : public APickupBase
{
	GENERATED_BODY()
public:
	//void SetIsActive(bool NewIsActive);
	virtual void InteractWithPlayer() override;

	void ActivateGoal(bool NewActive);

protected:
	virtual void BeginPlay() override;
private:

	UPROPERTY(EditAnywhere, Category = "Goal")
		FName NextLevel = FName("LEVEL_1");

	UPROPERTY(EditAnywhere, Category = "Goal")
		bool bIsActiveAtLevelStart = false;
};
