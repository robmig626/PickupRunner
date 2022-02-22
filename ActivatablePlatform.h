// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActivatablePlatform.generated.h"

UCLASS()
class PICKUPRUNNER_API AActivatablePlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActivatablePlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class USceneComponent* SceneRootComponent;

	UPROPERTY(VisibleAnywhere, Category = "Platform")
		class UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, Category = "Platform")
		class UBoxComponent* CollisionBox;

	class APickupRunnerCharacter* PlayerCharacter;

	UPROPERTY(EditAnywhere, Category = "Platform")
	bool bIsActivatable = true;

	UPROPERTY(VisibleAnywhere, Category = "Platform")
	bool bIsActive = false;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(
		class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(
		class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

	virtual void ActivateBehaviour();
	virtual void DeactivateBehaviour();

	UFUNCTION(BlueprintCallable)
	bool IsActive() const;

	UFUNCTION(BlueprintCallable)
	void SetIsActive(bool NewActive);

private:
	FVector DefaultPlatformBoxExtent = FVector(100.f, 100.f, 10.f);

};


