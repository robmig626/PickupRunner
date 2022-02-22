// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PickupRunnerGameState.generated.h"

/**
 * 
 */
UCLASS()
class PICKUPRUNNER_API APickupRunnerGameState : public AGameStateBase
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

private:
	class APickupRunnerCharacter* PlayerCharacter;
	bool LevelCleared = false;
	TArray<AActor*> FoundCoins;
	int32 TotalLevelCoins;
	TArray<AActor*> FoundGoals;
	TArray<AActor*> FoundHighJumpPickups;

public:
	void TestCoins();
	bool GetLevelCleared() const;
	void EnableGoals();
	void TestHighJumpPickups();

	UFUNCTION(BlueprintCallable)
	int32 GetTotalLevelCoins() const;
};
