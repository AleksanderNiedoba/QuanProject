// Copyright Epic Games, Inc. All Rights Reserved.


#include "QuanProjectGameModeBase.h"
#include "OverworldCameraPawn.h"
#include "OverworldPlayerController.h"

AQuanProjectGameModeBase::AQuanProjectGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	DefaultPawnClass = AOverworldCameraPawn::StaticClass();
	PlayerControllerClass = AOverworldPlayerController::StaticClass();
}
