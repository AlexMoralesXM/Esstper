// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "EsstperGameMode.h"
#include "EsstperCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEsstperGameMode::AEsstperGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
