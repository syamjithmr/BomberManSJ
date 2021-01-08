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
	int minutes;
	int seconds;
	void ConvertSecondsToMinutes();
	//Timer to countdown to TimeTillRescue.
	FTimerHandle TimeRemainingTimerHandle;
	void UpdateTimeRemaining();

	bool IsWon;
	//GameWonUI Component.
	UPROPERTY(EditAnywhere, Category = "Widgets")
		TSubclassOf<class UUserWidget> GameWonUIClass;
	UUserWidget* GameWonUI;
	UFUNCTION(BlueprintNativeEvent)
		void GameWon(class ABomberManSJCharacter* Winner);
	virtual void GameWon_Implementation(class ABomberManSJCharacter* Winner);
	UPROPERTY(BlueprintReadOnly)
		FString WinnerName;

	bool IsDraw;
	//GameWonUI Component.
	UPROPERTY(EditAnywhere, Category = "Widgets")
		TSubclassOf<class UUserWidget> GameDrawUIClass;
	UUserWidget* GameDrawUI;
	UFUNCTION(BlueprintNativeEvent)
		void GameDraw();
	void GameDraw_Implementation();

	UPROPERTY(BlueprintReadWrite)
		bool BlastIsChained;
	UPROPERTY(BlueprintReadWrite)
		bool BlastKilledOne;
	UFUNCTION(BlueprintCallable)
		void CheckPlayersDeadStatus();

	void UpdatePlayerStats();
	void AddPowerUps();
	UPROPERTY(EditAnywhere)
		int PowerUpSpawnProbability;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
