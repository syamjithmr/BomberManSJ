// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberManSJCharacter.h"
#include "Bomb.h"
#include "WallBase.h"
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

	AvailableBombs = 1;
	BombPower = 1;
	IsDead = false;

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
}

void ABomberManSJCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

void ABomberManSJCharacter::PlaceBomb()
{
	if (AvailableBombs > 0 && !IsDead)
	{
		ABomb* currBomb = GetWorld()->SpawnActor<ABomb>(BombClass, CurrTilePos, FRotator::ZeroRotator);
		currBomb->ParentPlayer = this;
		currBomb->BombPower = BombPower;
		currBomb->InitBlastLocations();
		AvailableBombs--;
	}
}
