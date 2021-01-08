// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberManSJCharacter.h"
#include "Bomb.h"
#include "WallBase.h"
#include "BomberManSJGameInstance.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

ABomberManSJCharacter::ABomberManSJCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

// Called when the game starts or when spawned
void ABomberManSJCharacter::BeginPlay()
{
	Super::BeginPlay();

	FVector temp;
	UGameplayStatics::GetActorOfClass(GetWorld(), AWallBase::StaticClass())->GetActorBounds(false, temp, WallExtent);

	//Set initial valus from the GameInstance. These are the values carried over from previous round.
	//The values set here are for Player 1. Player 2 values are set in GameMode, after calling CreatePlayer().
	UBomberManSJGameInstance* gameInstance = Cast<UBomberManSJGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	AvailableBombs = gameInstance->AvailableBombs[0];
	BombPower = gameInstance->BombPower[0];
	Score = gameInstance->Score[0];
	IsDead = false;
	PlayerName = "Player 1";
}

void ABomberManSJCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

void ABomberManSJCharacter::PlaceBomb()
{
	//If bombs are available, then spawn a bomb and initialize the BlastLocations array.
	//The bomb will blast after a Timer goes off. Te timer is set in Bomb Blueprint.
	if (AvailableBombs > 0)
	{
		ABomb* currBomb = GetWorld()->SpawnActor<ABomb>(BombClass, CurrTilePos, FRotator::ZeroRotator);
		currBomb->ParentPlayer = this;
		currBomb->BombPower = BombPower;
		currBomb->InitBlastLocations();
		//AvailableBombs is incremented once the blast is happened.
		AvailableBombs--;
	}
}

