// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberManSJPlayerController.h"
#include "BomberManSJCharacter.h"

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
	
	int32 id = GetLocalPlayer()->GetControllerId();
	UE_LOG(LogTemp, Warning, TEXT("%d"), id)
	if (id == 0)
	{
		InputComponent->BindAction("PlaceBombP1", EInputEvent::IE_Pressed, this, &ABomberManSJPlayerController::PlaceBomb);

		InputComponent->BindAxis("MoveForwardP1", this, &ABomberManSJPlayerController::MoveForward);
		InputComponent->BindAxis("MoveRightP1", this, &ABomberManSJPlayerController::MoveRight);
	}
	else
	{
		InputComponent->BindAction("PlaceBombP2", EInputEvent::IE_Pressed, this, &ABomberManSJPlayerController::PlaceBomb);

		InputComponent->BindAxis("MoveForwardP2", this, &ABomberManSJPlayerController::MoveForward);
		InputComponent->BindAxis("MoveRightP2", this, &ABomberManSJPlayerController::MoveRight);
	}
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
