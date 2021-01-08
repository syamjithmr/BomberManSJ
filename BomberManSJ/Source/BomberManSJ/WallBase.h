// Class representing walls.

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

	// I the wall can be breaked in the blast or not.
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool IsBreakabale;
	//The PowerUps that can be spawned. Add them in the Blueprint.
	UPROPERTY(EditAnywhere)
		TArray<TSubclassOf<class APowerUpBase>> PowerUpArray;
	//PowerUp contained in this wall. Only breakable walls contain PowerUps. This can be null.
	UPROPERTY(BlueprintReadOnly)
		APowerUpBase* PowerUp;
	//Create the PowerUp at Game start.
	void CreatePowerUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* WallMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
