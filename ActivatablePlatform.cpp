// Fill out your copyright notice in the Description page of Project Settings.


#include "ActivatablePlatform.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PickupRunnerCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AActivatablePlatform::AActivatablePlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRootComponent = CreateDefaultSubobject<USceneComponent>("Root Component");
	RootComponent = SceneRootComponent;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	StaticMesh->SetupAttachment(RootComponent);
	StaticMesh->SetCollisionProfileName("BlockAll");

	CollisionBox = CreateDefaultSubobject<UBoxComponent>("Box Collision");
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionProfileName("Trigger");
	CollisionBox->SetBoxExtent(DefaultPlatformBoxExtent);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AActivatablePlatform::OnOverlapBegin);

}

// Called when the game starts or when spawned
void AActivatablePlatform::BeginPlay()
{
	Super::BeginPlay();
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AActivatablePlatform::OnOverlapEnd);
	PlayerCharacter = Cast<APickupRunnerCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

// Called every frame
void AActivatablePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActivatablePlatform::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (PlayerCharacter && OtherActor == PlayerCharacter)
	{
		ActivateBehaviour();
	}
}

void AActivatablePlatform::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (PlayerCharacter && OtherActor == PlayerCharacter)
	{
		DeactivateBehaviour();
	}
}

void AActivatablePlatform::ActivateBehaviour()
{
	SetIsActive(true);
}

void AActivatablePlatform::DeactivateBehaviour()
{
	SetIsActive(false);
}

bool AActivatablePlatform::IsActive() const
{
	return bIsActive;
}

void AActivatablePlatform::SetIsActive(bool NewActive)
{
	bIsActive = NewActive;
}