// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberManSJGameMode.h"
#include "BomberManSJPlayerController.h"
#include "BomberManSJCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABomberManSJGameMode::ABomberManSJGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ABomberManSJPlayerController::StaticClass();
}