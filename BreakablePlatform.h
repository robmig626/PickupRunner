// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActivatablePlatform.h"
#include "BreakablePlatform.generated.h"

/**
 * 
 */
UCLASS()
class PICKUPRUNNER_API ABreakablePlatform : public AActivatablePlatform
{
	GENERATED_BODY()

public:
	virtual void ActivateBehaviour() override;
	virtual void DeactivateBehaviour() override;
	void BreakPlatform();
	void ReformPlatform();

protected:
	FTimerHandle PlatformTimerHandle;
	
	UPROPERTY(EditAnywhere, Category = "Breakable")
	bool bIsBreakable = false;

	UPROPERTY(EditAnywhere, Category = "Breakable")
	bool bIsReformable = true;

	UPROPERTY(EditAnywhere, Category = "Breakable")
	float BreakDelay = 2.f;

	UPROPERTY(EditAnywhere, Category = "Breakable")
	float ReformDelay = 5.f;
};
