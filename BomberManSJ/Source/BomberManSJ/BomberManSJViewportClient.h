// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "BomberManSJViewportClient.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMANSJ_API UBomberManSJViewportClient : public UGameViewportClient
{
	GENERATED_BODY()
	
	virtual bool InputKey(const FInputKeyEventArgs& EventArgs) override;
};
