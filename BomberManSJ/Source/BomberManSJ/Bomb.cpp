// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomb.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ABomb::ABomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BombMesh = CreateDefaultSubobject<UStaticMeshComponent>("Bomb Mesh");
	BombMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABomb::BeginPlay()
{
	Super::BeginPlay();
	
	if (BombBlastEffect)
	{
		BombBlastComponent = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), BombBlastEffect, GetTransform(), true, EPSCPoolMethod::None, false);
		BombBlastComponent->SetRelativeScale3D(BombBlastComponent->GetRelativeScale3D() * 5);
		BombBlastComponent->Activate();
	}
}

// Called every frame
void ABomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

