// Copyright Epic Games, Inc. All Rights Reserved.

#include "EngineProjectGameMode.h"
#include "EngineProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEngineProjectGameMode::AEngineProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
