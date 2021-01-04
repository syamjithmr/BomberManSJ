// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BomberManSJCharacter.generated.h"

UCLASS(Blueprintable)
class ABomberManSJCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABomberManSJCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ABomb> BombClass;
	
	void PlaceBomb();
};

