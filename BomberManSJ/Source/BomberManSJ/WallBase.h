// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WallBase.generated.h"

UCLASS()
class BOMBERMANSJ_API AWallBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWallBase();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool IsBreakabale;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* WallMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
