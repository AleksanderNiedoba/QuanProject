// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/InteractComponent.h"
#include "InteractionHandler.generated.h"

/**
 * 
 */
UCLASS()
class OVERWORLDBASE_API UInteractionHandler : public UObject
{
	GENERATED_BODY()

public: 
	void UpdateInteractions(FHitResult);
protected:
	void CheckForRelease();
private: 
	UInteractComponent* HoveredComponent;
};
