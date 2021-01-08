// Fill out your copyright notice in the Description page of Project Settings.


#include "WallBase.h"
#include "PowerUpBase.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AWallBase::AWallBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WallMesh = CreateDefaultSubobject<UStaticMeshComponent>("Wall Mesh");
	WallMesh->SetupAttachment(RootComponent);

	PowerUp = nullptr;
}

// Called when the game starts or when spawned
void AWallBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWallBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWallBase::CreatePowerUp()
{
	//Create a Random PowerUp and attach that to this Wall.
	int PowerUpIndex = UKismetMathLibrary::RandomIntegerInRange(0, PowerUpArray.Num() - 1);
	if (PowerUpArray.Num() != 0)
	{
		UClass* PowerUpClass = PowerUpArray[PowerUpIndex].Get();
		PowerUp = GetWorld()->SpawnActor<APowerUpBase>(PowerUpClass, GetTransform());
		PowerUp->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
	}
}