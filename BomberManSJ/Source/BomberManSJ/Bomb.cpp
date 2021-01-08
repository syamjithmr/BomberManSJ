// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomb.h"
#include "BomberManSJCharacter.h"
#include "WallBase.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ABomb::ABomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BombMesh = CreateDefaultSubobject<UStaticMeshComponent>("Bomb Mesh");
	BombMesh->SetupAttachment(RootComponent);

	BombPower = 1;
}

// Called when the game starts or when spawned
void ABomb::BeginPlay()
{
	Super::BeginPlay();

	FVector temp;
	GetActorBounds(false, temp, BombExtent);
	SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + BombExtent.Z));
}

// Called every frame
void ABomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABomb::InitBlastLocations()
{
	BlastLocations.Add(GetActorLocation());

	AddBlastLocationsInDirection(FVector::LeftVector);
	AddBlastLocationsInDirection(FVector::RightVector);
	AddBlastLocationsInDirection(FVector::ForwardVector);
	AddBlastLocationsInDirection(FVector::BackwardVector);
}

void ABomb::AddBlastLocationsInDirection(FVector Direction)
{
	int blastLength = BombPower;
	FHitResult hitResult;
	FVector start = GetActorLocation();
	FVector end = GetActorLocation() + Direction * ParentPlayer->WallExtent.X * 2 * BombPower;

	//Casting a ray from bomb location to given direction.
	if (GetWorld()->LineTraceSingleByObjectType(hitResult, start, end, FCollisionObjectQueryParams::AllStaticObjects))
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor Name: %s"), *hitResult.GetActor()->GetFName().ToString())

		//Stop the blast When a wall is hit.
		blastLength = ((hitResult.ImpactPoint - GetActorLocation()).Size()) / (ParentPlayer->WallExtent.X * 2);
		if (AWallBase* wall = Cast<AWallBase>(hitResult.GetActor()))
		{
			//If it is a breakable wall, that wall is also icluded in the blast.
			if (wall->IsBreakabale)
				blastLength++;
		}
	}
	//Add Blast locations to the Array.
	for (int i = 1; i <= blastLength; i++)
	{
		BlastLocations.Add(GetActorLocation() + Direction * ParentPlayer->WallExtent.X * 2 * i);
	}
}
