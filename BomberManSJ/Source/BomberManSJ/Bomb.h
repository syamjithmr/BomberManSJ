// This class represent the Bomb object.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bomb.generated.h"

UCLASS()
class BOMBERMANSJ_API ABomb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties.
	ABomb();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class UStaticMeshComponent* BombMesh;
	//Player that created this bomb.
	UPROPERTY(BlueprintReadOnly)
		class ABomberManSJCharacter* ParentPlayer;
	//Locations where the blast should happen.
	UPROPERTY(BlueprintReadOnly)
		TArray<FVector> BlastLocations;
	//Howmuch length should the blast cover.
	int BombPower;
	//The bounds of bomb object.
	FVector BombExtent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Calculates the blast locations in the given direction.
	void AddBlastLocationsInDirection(FVector Direction);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Initializes the BlastLocations Array. Calls AddBlastLocationsInDirection 4 times.
	void InitBlastLocations();
};
