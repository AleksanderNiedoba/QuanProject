// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "OverworldBaseSettings.h"
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
	void RegisterMultiselectionActors(TArray<AActor*> OverlapingActors);
	void HandleMultiselectionEnd();
	void Init();
protected:
	void ReleaseMultiselectHovers();
	void CheckForRelease();
	void UpdateInteractionContext(EInteractionContext);
private:
	UPROPERTY()
	UInteractComponent* HoveredComponent;
	UPROPERTY()
	TArray<UInteractComponent*> MultiselectedComponents;
};
