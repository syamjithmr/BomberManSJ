// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberManSJPlayerController.h"
#include "BomberManSJCharacter.h"
#include "BomberManSJGameManager.h"
#include "Kismet/GameplayStatics.h"

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

	GameManager = Cast<ABomberManSJGameManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ABomberManSJGameManager::StaticClass()));
}

void ABomberManSJPlayerController::MoveForward(float MoveRate)
{
	if(!GameManager->IsWon && !GameManager->IsDraw)
		GetPawn()->AddMovementInput(FVector::ForwardVector, MoveRate);
}

void ABomberManSJPlayerController::MoveRight(float MoveRate)
{
	if (!GameManager->IsWon && !GameManager->IsDraw)
		GetPawn()->AddMovementInput(FVector::RightVector, MoveRate);
}

void ABomberManSJPlayerController::PlaceBomb()
{
	if (!GameManager->IsWon && !GameManager->IsDraw)
		Cast<ABomberManSJCharacter>(GetPawn())->PlaceBomb();
}
