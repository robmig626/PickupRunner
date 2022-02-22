// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatformTrack.h"
#include "Components/SceneComponent.h"
#include "Components/SplineComponent.h"

// Sets default values
AMovingPlatformTrack::AMovingPlatformTrack()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRootComponent = CreateDefaultSubobject<USceneComponent>("Root Component");
	RootComponent = SceneRootComponent;

	TrackSplineComponent = CreateDefaultSubobject<USplineComponent>("Track Spline");
	TrackSplineComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMovingPlatformTrack::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingPlatformTrack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

