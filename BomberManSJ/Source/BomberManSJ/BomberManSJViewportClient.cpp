// Fill out your copyright notice in the Description page of Project Settings.


#include "BomberManSJViewportClient.h"

bool UBomberManSJViewportClient::InputKey(const FInputKeyEventArgs& EventArgs)
{
	if (IgnoreInput() || EventArgs.IsGamepad() || EventArgs.Key.IsMouseButton())
	{
		return Super::InputKey(EventArgs);
	}
	else
	{
		// Propagate keyboard events to all players, so that both Players can use Keyboard inputs.
		UEngine* const Engine = GetOuterUEngine();
		int32 const NumPlayers = Engine ? Engine->GetNumGamePlayers(this) : 0;
		bool bRetVal = false;
		for (int32 i = 0; i < NumPlayers; i++)
		{
			FInputKeyEventArgs tempArgs = EventArgs;
			tempArgs.ControllerId = i;
			bRetVal = Super::InputKey(tempArgs) || bRetVal;
		}
		return bRetVal;
	}
}
