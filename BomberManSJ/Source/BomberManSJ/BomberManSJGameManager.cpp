// Fill out your copyright notice in the Description page of Project Settings.


#include "BomberManSJGameManager.h"
#include "BomberManSJCharacter.h"
#include "BomberManSJGameInstance.h"
#include "WallBase.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Blueprint/UserWidget.h"

// Sets default values
ABomberManSJGameManager::ABomberManSJGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TimeRemaining = 30;
	IsWon = false;
	WinnerName = "";
	IsDraw = false;
	BlastIsChained = false;
	BlastKilledOne = false;
	PowerUpSpawnProbability = 5;
}

// Called when the game starts or when spawned
void ABomberManSJGameManager::BeginPlay()
{
	Super::BeginPlay();

	ConvertSecondsToMinutes();

	UBomberManSJGameInstance* gameInstance = Cast<UBomberManSJGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	//Start the timer for counting down TimeTillRescue.
	GetWorldTimerManager().SetTimer(TimeRemainingTimerHandle, this, &ABomberManSJGameManager::UpdateTimeRemaining, 1.0f, true);
	//If this is initial launch, pause the timer. It is resumed when the Start UI is closed.
	if (gameInstance->InitialLaunch)
		GetWorldTimerManager().PauseTimer(TimeRemainingTimerHandle);

	AddPowerUps();
}

// Called every frame
void ABomberManSJGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABomberManSJGameManager::UpdateTimeRemaining()
{
	//Countdown.
	TimeRemaining--;
	ConvertSecondsToMinutes();

	//Check if the countdown have become 0. If it is and the round is not won, draw the game.
	if (TimeRemaining < 1)
	{
		GetWorldTimerManager().ClearTimer(TimeRemainingTimerHandle);
		if (!IsWon)
			GameDraw();
	}
}

void ABomberManSJGameManager::ConvertSecondsToMinutes()
{
	//Convert TimeRemaining to mm:ss format to be displayed in the HUD.
	minutes = TimeRemaining / 60;
	seconds = TimeRemaining % 60;
	TimeRemainingText = FString::Printf(TEXT("%02d:%02d"), minutes, seconds);
}

void ABomberManSJGameManager::GameWon_Implementation(ABomberManSJCharacter* Winner)
{
	GetWorldTimerManager().PauseTimer(TimeRemainingTimerHandle);
	WinnerName = Winner->PlayerName;
	IsWon = true;
	//Increment player's score.
	Winner->Score++;
	//UpdatePlayerStats();

	//Initialize and display GameWon UI.
	if (GameWonUIClass)
		GameWonUI = CreateWidget(GetWorld(), GameWonUIClass);
	if (GameWonUI)
		GameWonUI->AddToViewport();
}

void ABomberManSJGameManager::GameDraw_Implementation()
{
	GetWorldTimerManager().PauseTimer(TimeRemainingTimerHandle);
	IsDraw = true;

	//UpdatePlayerStats();

	//Initialize and display GameDraw UI.
	if (GameDrawUIClass)
		GameDrawUI = CreateWidget(GetWorld(), GameDrawUIClass);
	if (GameDrawUI)
		GameDrawUI->AddToViewport();
}

void ABomberManSJGameManager::UpdatePlayerStats()
{
	TArray<AActor*> Players;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABomberManSJCharacter::StaticClass(), Players);
	ABomberManSJCharacter* Player1 = Cast<ABomberManSJCharacter>(Players[0]);
	ABomberManSJCharacter* Player2 = Cast<ABomberManSJCharacter>(Players[1]);
	UBomberManSJGameInstance* gameInstance = Cast<UBomberManSJGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	gameInstance->AvailableBombs[0] = Player1->AvailableBombs;
	gameInstance->BombPower[0] = Player1->BombPower;
	gameInstance->Score[0] = Player1->Score;
	gameInstance->AvailableBombs[1] = Player2->AvailableBombs;
	gameInstance->BombPower[1] = Player2->BombPower;
	gameInstance->Score[1] = Player2->Score;
}

void ABomberManSJGameManager::AddPowerUps()
{
	//Get all the walls in world.
	TArray<AActor*> wallsInWorld;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWallBase::StaticClass(), wallsInWorld);
	//Limit number of PowerUps to 1/3 of walls in the world.
	int maxPowerUps = wallsInWorld.Num() / 3;
	for (int i = 0; i < wallsInWorld.Num(); i++)
	{
		AWallBase* wall = Cast<AWallBase>(wallsInWorld[i]);
		if (wall->IsBreakabale)
		{
			//Randomly decide if PowerUp need to be spawned or not. 1/PowerUpSpawnProbability+1 chance.
			if (UKismetMathLibrary::RandomIntegerInRange(0, PowerUpSpawnProbability) == 0&& maxPowerUps>0)
			{
				wall->CreatePowerUp();
				maxPowerUps--;
			}
		}
	}
}

void ABomberManSJGameManager::CheckPlayersDeadStatus()
{
	TArray<AActor*> Players;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABomberManSJCharacter::StaticClass(), Players);
	ABomberManSJCharacter* Player1 = Cast<ABomberManSJCharacter>(Players[0]);
	ABomberManSJCharacter* Player2 = Cast<ABomberManSJCharacter>(Players[1]);
	if (Player1->IsDead && Player2->IsDead) //If both players are dead, draw the round.
		GameDraw();
	else //Else make the player alive the winner of this round.
		GameWon(Player1->IsDead ? Player2 : Player1);
}

void ABomberManSJGameManager::UnpauseTimer()
{
	if (GetWorldTimerManager().IsTimerPaused(TimeRemainingTimerHandle))
		GetWorldTimerManager().UnPauseTimer(TimeRemainingTimerHandle);
}
