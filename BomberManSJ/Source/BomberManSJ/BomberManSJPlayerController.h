// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BomberManSJPlayerController.generated.h"

UCLASS()
class ABomberManSJPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ABomberManSJPlayerController();

protected:
	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	//Used to check if the game is won or draw. If either one is true, the input is not processed.
	class ABomberManSJGameManager* GameManager;

	//Methods added by me.
	//Input delegate functions.
	void MoveForward(float MoveRate);
	void MoveRight(float MoveRate);
	void PlaceBomb();
};


