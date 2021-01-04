// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberManSJPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "BomberManSJCharacter.h"
#include "Engine/World.h"

ABomberManSJPlayerController::ABomberManSJPlayerController()
{
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ABomberManSJPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void ABomberManSJPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("PlaceBomb", EInputEvent::IE_Pressed, this, &ABomberManSJPlayerController::PlaceBomb);

	InputComponent->BindAxis("MoveForward", this, &ABomberManSJPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABomberManSJPlayerController::MoveRight);
}

void ABomberManSJPlayerController::MoveForward(float MoveRate)
{
	GetPawn()->AddMovementInput(FVector::ForwardVector, MoveRate);
}

void ABomberManSJPlayerController::MoveRight(float MoveRate)
{
	GetPawn()->AddMovementInput(FVector::RightVector, MoveRate);
}

void ABomberManSJPlayerController::PlaceBomb()
{
	Cast<ABomberManSJCharacter>(GetPawn())->PlaceBomb();
}
