// Fill out your copyright notice in the Description page of Project Settings.


#include "OverworldStatics.h"
#include "IPlayerController.h"

FVector UOverworldStatics::GetMouseWorldHitLocation(const UObject* WorldContextObject)
{
	FVector HitLocation;
	if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (auto* IPlayerController = Cast<IIPlayerController>(PlayerController))
		{
			HitLocation = IPlayerController->GetMouseHitLocation();
		}
	}
	return HitLocation;
}