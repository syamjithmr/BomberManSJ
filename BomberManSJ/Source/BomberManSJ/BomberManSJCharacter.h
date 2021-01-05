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


	UPROPERTY(BlueprintReadWrite)
		bool IsDead;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class ABomb> BombClass;
	UPROPERTY(BlueprintReadWrite)
		FVector CurrTilePos;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int AvailableBombs;
	FVector WallExtent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void PlaceBomb();
};

