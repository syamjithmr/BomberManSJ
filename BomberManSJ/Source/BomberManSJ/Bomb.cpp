// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomb.h"
#include "BomberManSJCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ABomb::ABomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//RootComponent = CreateDefaultSubobject<USceneComponent>("Root Component");

	BombMesh = CreateDefaultSubobject<UStaticMeshComponent>("Bomb Mesh");
	BombMesh->SetupAttachment(RootComponent);

	BombPower = 2;
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

	int blastLength = BombPower;
	FHitResult hitResult;
	FVector start = GetActorLocation();// +FVector::LeftVector * (BombExtent.Y + 10);
	FVector end = GetActorLocation() + FVector::LeftVector * ParentPlayer->WallExtent.Y * 2 * BombPower;
	if (GetWorld()->LineTraceSingleByObjectType(hitResult, start, end, FCollisionObjectQueryParams::AllStaticObjects))
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor Name: %s"), *hitResult.GetActor()->GetFName().ToString())
		
		blastLength = ((hitResult.ImpactPoint - GetActorLocation()).Size() - ParentPlayer->WallExtent.Y) / (ParentPlayer->WallExtent.Y * 2);
	}
	UE_LOG(LogTemp, Warning, TEXT("Blast Length: %d"), blastLength);
	for (int i = 1; i <= blastLength; i++)
	{
		BlastLocations.Add(GetActorLocation() + FVector::LeftVector * ParentPlayer->WallExtent.Y * 2 * i);
	}

	blastLength = BombPower;
	start = GetActorLocation();// +FVector::RightVector * (BombExtent.Y + 10);
	end = GetActorLocation() + FVector::RightVector * ParentPlayer->WallExtent.Y * 2 * BombPower;
	if (GetWorld()->LineTraceSingleByObjectType(hitResult, start, end, FCollisionObjectQueryParams::AllStaticObjects))
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor Name: %s"), *hitResult.GetActor()->GetFName().ToString())

			blastLength = ((hitResult.ImpactPoint - GetActorLocation()).Size() - ParentPlayer->WallExtent.Y) / (ParentPlayer->WallExtent.Y * 2);
	}
	for (int i = 1; i <= blastLength; i++)
	{
		BlastLocations.Add(GetActorLocation() + FVector::RightVector * ParentPlayer->WallExtent.Y * 2 * i);
	}

	blastLength = BombPower;
	start = GetActorLocation();// +FVector::ForwardVector * (BombExtent.X + 10);
	end = GetActorLocation() + FVector::ForwardVector * ParentPlayer->WallExtent.X * 2 * BombPower;
	if (GetWorld()->LineTraceSingleByObjectType(hitResult, start, end, FCollisionObjectQueryParams::AllStaticObjects))
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor Name: %s"), *hitResult.GetActor()->GetFName().ToString())

			blastLength = ((hitResult.ImpactPoint - GetActorLocation()).Size() - ParentPlayer->WallExtent.X) / (ParentPlayer->WallExtent.X * 2);
	}
	for (int i = 1; i <= blastLength; i++)
	{
		BlastLocations.Add(GetActorLocation() + FVector::ForwardVector * ParentPlayer->WallExtent.X * 2 * i);
	}

	blastLength = BombPower;
	start = GetActorLocation();// +FVector::BackwardVector * (BombExtent.X + 10);
	end = GetActorLocation() + FVector::BackwardVector * ParentPlayer->WallExtent.X * 2 * BombPower;
	if (GetWorld()->LineTraceSingleByObjectType(hitResult, start, end, FCollisionObjectQueryParams::AllStaticObjects))
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor Name: %s"), *hitResult.GetActor()->GetFName().ToString())

			blastLength = ((hitResult.ImpactPoint - GetActorLocation()).Size() - ParentPlayer->WallExtent.X) / (ParentPlayer->WallExtent.X * 2);
	}
	for (int i = 1; i <= blastLength; i++)
	{
		BlastLocations.Add(GetActorLocation() + FVector::BackwardVector * ParentPlayer->WallExtent.X * 2 * i);
	}
}

