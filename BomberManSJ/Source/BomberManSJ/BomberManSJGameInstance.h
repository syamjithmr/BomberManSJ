// GameInstance class is used to store data to be carried over to several rounds.

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

	//These properties store data of both players.
	UPROPERTY(BlueprintReadWrite)
		TArray<int> Score;
	UPROPERTY(BlueprintReadWrite)
		TArray<int> BombPower;
	UPROPERTY(BlueprintReadWrite)
		TArray<int> AvailableBombs;
	//Decides if this is the first round after launching the game.
	UPROPERTY(BlueprintReadWrite)
		bool InitialLaunch;
};
