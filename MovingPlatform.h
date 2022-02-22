// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BreakablePlatform.h"
#include "Components/TimelineComponent.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PICKUPRUNNER_API AMovingPlatform : public ABreakablePlatform
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

	virtual void ActivateBehaviour() override;
	virtual void DeactivateBehaviour() override;

	UFUNCTION(BlueprintCallable)
	void TimelineProgress(float Value);

	void PlatformDisappear();
	void PlatformReappear();

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Movement")
	bool bIsMovable = true;

	UPROPERTY(EditAnywhere, Category = "Movement")
	bool bLooping = true;

	UPROPERTY(EditAnywhere, Category = "Movement")
	bool bIsAlwaysActive = false;

	UPROPERTY(EditAnywhere, Category = "Movement")
	bool bIsWaiting = false;

	UPROPERTY(EditAnywhere, Category = "Movement")
	bool bWaitsAtStart = false;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovementSpeed = 100.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	class AMovingPlatformTrack* Track;

	UPROPERTY(EditAnywhere, Category = "Movement")
	class UCurveFloat* BehaviourType;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float InitialPercentOffset = 0.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float PlatformDisappearThreshold = 0.99f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float PlatformReappearThreshold = 0.01f;

	FTimeline CurveTimeline;

private:
	float TotalTrackDistance;
	class USplineComponent* TrackSpline;

	float DistanceOnTrack=0.f;
};
