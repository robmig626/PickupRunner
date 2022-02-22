// Copyright Epic Games, Inc. All Rights Reserved.

#include "PickupRunnerGameMode.h"
#include "PickupRunnerCharacter.h"
#include "UObject/ConstructorHelpers.h"

APickupRunnerGameMode::APickupRunnerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
