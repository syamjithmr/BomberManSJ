// Fill out your copyright notice in the Description page of Project Settings.


#include "WallBase.h"

// Sets default values
AWallBase::AWallBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WallMesh = CreateDefaultSubobject<UStaticMeshComponent>("Wall Mesh");
	WallMesh->SetupAttachment(RootComponent);
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

