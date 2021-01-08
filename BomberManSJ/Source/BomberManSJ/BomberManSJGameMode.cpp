// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberManSJGameMode.h"
#include "BomberManSJPlayerController.h"
#include "BomberManSJCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABomberManSJGameMode::ABomberManSJGameMode()
{
	// Use our custom PlayerController class
	PlayerControllerClass = ABomberManSJPlayerController::StaticClass();
	//Player 2 is created in the GameMode Blueprint.
}

