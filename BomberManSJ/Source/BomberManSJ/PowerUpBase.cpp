// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpBase.h"


// Sets default values
APowerUpBase::APowerUpBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

	PowerUpMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	PowerUpMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APowerUpBase::BeginPlay()
{
	Super::BeginPlay();

	SetActorHiddenInGame(true);
	//To stop the Power up from getting destroyed in the blast for the first time.
	SetActorEnableCollision(false);
}

// Called every frame
void APowerUpBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APowerUpBase::ActivatePowerUp()
{
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
}