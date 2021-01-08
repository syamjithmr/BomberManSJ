// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PowerUpBase.generated.h"

UCLASS()
class BOMBERMANSJ_API APowerUpBase : public AActor
{
	GENERATED_BODY()
	

public:
	// Sets default values for this actor's properties
	APowerUpBase();

	UFUNCTION(BlueprintCallable)
		void ActivatePowerUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* PowerUpMesh;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
