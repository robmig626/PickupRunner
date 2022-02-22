// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupBase.generated.h"

UCLASS()
class PICKUPRUNNER_API APickupBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//UPROPERTY(EditAnywhere, Category = "Pickup")
	FVector CollisionBoxExtent = FVector(64.f, 64.f, 64.f);

	UPROPERTY(EditAnywhere, Category = "Pickup")
	FRotator RotationRate = FRotator(0.f, 0.f, 100.f);

	//UPROPERTY(EditAnywhere, Category = "Pickup")
	class USceneComponent* SceneRootComponent;

	UPROPERTY(VisibleAnywhere, Category = "Pickup")
	class UStaticMeshComponent* StaticMesh;

	//UPROPERTY(EditAnywhere, Category = "Pickup")
	class APickupRunnerCharacter* PlayerCharacter;

	UPROPERTY(VisibleAnywhere, Category = "Pickup")
	class UBoxComponent* CollisionBox;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void InteractWithPlayer();

	UFUNCTION()
	void OnOverlapBegin(
		class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor, 
		class UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, 
		bool bFromSweep, 
		const FHitResult& SweepResult);

};
