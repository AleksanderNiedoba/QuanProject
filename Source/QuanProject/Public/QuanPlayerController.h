// Copyright Quan Project 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OverworldPlayerController.h"
#include "QuanPlayerController.generated.h"

UCLASS()
class QUANPROJECT_API AQuanPlayerController : public AOverworldPlayerController
{
	GENERATED_BODY()

	public:
	UFUNCTION(BlueprintPure, Category = "Interactions")
	EInteractionContext GetCurrentInteractionContext();

	UFUNCTION(BlueprintCallable, Category = "Interactions")
	void SetInteractionContext(EInteractionContext NewContext);
	
};
