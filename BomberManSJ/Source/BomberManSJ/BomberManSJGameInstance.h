// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BomberManSJGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMANSJ_API UBomberManSJGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UBomberManSJGameInstance();

	UPROPERTY(BlueprintReadWrite)
		TArray<int> Score;
	UPROPERTY(BlueprintReadWrite)
		TArray<int> BombPower;
	UPROPERTY(BlueprintReadWrite)
		TArray<int> AvailableBombs;
	UPROPERTY(BlueprintReadWrite)
		bool InitialLaunch;
};
