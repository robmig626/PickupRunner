// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupBase.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "PickupRunnerCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APickupBase::APickupBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRootComponent = CreateDefaultSubobject<USceneComponent>("Root Component");
	RootComponent = SceneRootComponent;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>("CollisionBox");
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetBoxExtent(CollisionBoxExtent);
	CollisionBox->SetCollisionProfileName("Trigger");
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &APickupBase::OnOverlapBegin);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(RootComponent);
	StaticMesh->SetCollisionProfileName("OverlapAllDynamic");

}

// Called when the game starts or when spawned
void APickupBase::BeginPlay()
{
	Super::BeginPlay();
	PlayerCharacter = Cast<APickupRunnerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void APickupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	StaticMesh->AddRelativeRotation(RotationRate*DeltaTime);
}

void APickupBase::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (PlayerCharacter && OtherActor == PlayerCharacter)
	{
		InteractWithPlayer();
	}
}

void APickupBase::InteractWithPlayer()
{
	//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, "Interacting with player!");
}

