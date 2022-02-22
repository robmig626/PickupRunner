// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatformTrack.generated.h"

UCLASS()
class PICKUPRUNNER_API AMovingPlatformTrack : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatformTrack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	class USceneComponent* SceneRootComponent;
	UPROPERTY(VisibleAnywhere)
	class USplineComponent* TrackSplineComponent;

};
