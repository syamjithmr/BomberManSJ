// This Class represent a Power Up.

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

	//Activates a PowerUp when explosion is completed.
	UFUNCTION(BlueprintCallable)
		void ActivatePowerUp();

protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* PowerUpMesh;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
