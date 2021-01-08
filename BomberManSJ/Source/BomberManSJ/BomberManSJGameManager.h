// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BomberManSJGameManager.generated.h"

UCLASS()
class BOMBERMANSJ_API ABomberManSJGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABomberManSJGameManager();

	//Time remaining for the level(Seconds).
	UPROPERTY(EditAnywhere)
		int TimeRemaining;
	//Time to be displayed in In-Game HUD.
	UPROPERTY(BlueprintReadOnly)
		FString TimeRemainingText;
	//Timer to countdown TimeRemaining.
	FTimerHandle TimeRemainingTimerHandle;
	void UpdateTimeRemaining();
	//To Resume the timer after InitialLaunch.
	UFUNCTION(BlueprintCallable)
		void UnpauseTimer();

	bool IsWon;
	//GameWonUI Component.
	UPROPERTY(EditAnywhere, Category = "Widgets")
		TSubclassOf<class UUserWidget> GameWonUIClass;
	//Called when a player is won the round. Overridden in Blueprint.
	UFUNCTION(BlueprintNativeEvent)
		void GameWon(class ABomberManSJCharacter* Winner);
	virtual void GameWon_Implementation(class ABomberManSJCharacter* Winner);
	//Winne's name.
	UPROPERTY(BlueprintReadOnly)
		FString WinnerName;

	bool IsDraw;
	//GameDrawUI Component.
	UPROPERTY(EditAnywhere, Category = "Widgets")
		TSubclassOf<class UUserWidget> GameDrawUIClass;
	//Called when the round is a Draw. Overridden in Blueprint.
	UFUNCTION(BlueprintNativeEvent)
		void GameDraw();
	void GameDraw_Implementation();

	//If the blast included another Bomb object.
	UPROPERTY(BlueprintReadWrite)
		bool BlastIsChained;
	//If the Blast killed a Player.
	UPROPERTY(BlueprintReadWrite)
		bool BlastKilledOne;
	//Check which players are dead, and decide Win/Draw condition.
	UFUNCTION(BlueprintCallable)
		void CheckPlayersDeadStatus();

	//Update the player Stats in GameInstance, to carry over to the next round.
	UFUNCTION(BlueprintCallable)
		void UpdatePlayerStats();
	//Add powerips to the level on game start.
	void AddPowerUps();
	UPROPERTY(EditAnywhere)
		int PowerUpSpawnProbability;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int minutes;
	int seconds;
	//Convert TimeRemaining to mm:ss format for displaying in the HUD.
	void ConvertSecondsToMinutes();

	UUserWidget* GameWonUI;

	UUserWidget* GameDrawUI;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
