// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bomb.generated.h"

UCLASS()
class BOMBERMANSJ_API ABomb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABomb();

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* BombMesh;
	UPROPERTY(BlueprintReadOnly)
		class ABomberManSJCharacter* ParentPlayer;
	UPROPERTY(BlueprintReadOnly)
		TArray<FVector> BlastLocations;
	int BombPower;
	FVector BombExtent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void AddBlastLocationsInDirection(FVector Direction);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void InitBlastLocations();
};
