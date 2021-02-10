// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IPlayerController.generated.h"


UINTERFACE(MinimalAPI)
class UIPlayerController : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class OVERWORLDBASE_API IIPlayerController
{
	GENERATED_IINTERFACE_BODY()

	virtual FVector GetMouseHitLocation() = 0;
	virtual void GetMouseDelta(float & MouseX, float & MouseY) = 0;
};
