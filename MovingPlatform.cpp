// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include "MovingPlatformTrack.h"
#include "Components/SplineComponent.h"
#include "Components/TimelineComponent.h"
#include "Components/StaticMeshComponent.h"


void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	if (Track)
	{
		TrackSpline = Cast<USplineComponent>(Track->GetComponentByClass(USplineComponent::StaticClass()));
		TotalTrackDistance = TrackSpline->GetSplineLength();
		SetActorLocation(TrackSpline->GetLocationAtDistanceAlongSpline((FMath::Clamp(InitialPercentOffset,0.f,1.f))*TotalTrackDistance,ESplineCoordinateSpace::World));
	}

	if (BehaviourType)
	{
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindUFunction(this,FName("TimelineProgress"));
		CurveTimeline.AddInterpFloat(BehaviourType, TimelineProgress);
		CurveTimeline.SetLooping(bLooping);
		CurveTimeline.SetPlaybackPosition(InitialPercentOffset * CurveTimeline.GetTimelineLength(), false);
		CurveTimeline.Play();
	}
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsActive||(bIsAlwaysActive && !bIsWaiting))
	{
		CurveTimeline.TickTimeline(DeltaTime * MovementSpeed/TotalTrackDistance);
	}

	if (!bIsActive && bWaitsAtStart)
	{
		if (DistanceOnTrack < 10.f)
		{
			bIsWaiting = true;
		}
	}

}

void AMovingPlatform::ActivateBehaviour()
{
	Super::ActivateBehaviour();
	if (bIsActivatable)
	{
		if (bIsWaiting)
		{
			bIsWaiting = false;
		}

		SetIsActive(true);
	}
}

void AMovingPlatform::DeactivateBehaviour()
{
	Super::DeactivateBehaviour();
	if (bIsActivatable)
	{
		SetIsActive(false);
	}
}

void AMovingPlatform::TimelineProgress(float Value)
{
	DistanceOnTrack = FMath::Lerp(0.f, TotalTrackDistance, Value);
	SetActorLocation(TrackSpline->GetLocationAtDistanceAlongSpline(DistanceOnTrack, ESplineCoordinateSpace::World));
	if ( CurveTimeline.GetPlaybackPosition()/CurveTimeline.GetTimelineLength() >= PlatformDisappearThreshold)
	{
		PlatformDisappear();
	}

	if (CurveTimeline.GetPlaybackPosition() / CurveTimeline.GetTimelineLength() <= PlatformReappearThreshold)
	{
		PlatformReappear();
	}
}

void AMovingPlatform::PlatformDisappear()
{
	SetActorHiddenInGame(true);
	StaticMesh->SetCollisionProfileName("NoCollision");
}

void AMovingPlatform::PlatformReappear()
{
	SetActorHiddenInGame(false);
	StaticMesh->SetCollisionProfileName("BlockAll");
}