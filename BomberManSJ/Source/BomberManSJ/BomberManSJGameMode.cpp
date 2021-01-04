// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberManSJGameMode.h"
#include "BomberManSJPlayerController.h"
#include "BomberManSJCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABomberManSJGameMode::ABomberManSJGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ABomberManSJPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}