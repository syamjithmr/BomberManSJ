// Fill out your copyright notice in the Description page of Project Settings.


#include "BomberManSJGameInstance.h"

UBomberManSJGameInstance::UBomberManSJGameInstance()
{
	Score = { 0, 0 };
	BombPower = { 1, 1 };
	AvailableBombs = { 1, 1 };
	InitialLaunch = true;
}