// Copyright Epic Games, Inc. All Rights Reserved.
// Class representing the player. 2 Players are created in game.

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

	UPROPERTY(BlueprintReadWrite)
		bool IsDead;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class ABomb> BombClass;
	//Position of tile the player is currently in. Bomb is spawned at this location.
	UPROPERTY(BlueprintReadWrite)
		FVector CurrTilePos;
	//Bombs available for this player.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int AvailableBombs;
	//Howmuch length should the blast cover.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int BombPower;
	//The bounds of wall object.
	FVector WallExtent;

	//Used to distiguish between players. This is used to display win message in UI.
	UPROPERTY(BlueprintReadWrite)
		FString PlayerName;
	//Player's score
	UPROPERTY(BlueprintReadWrite)
		int Score;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//Called to place a bomb in the current tile position.
	void PlaceBomb();
};

