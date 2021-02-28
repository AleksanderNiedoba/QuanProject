// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OverworldStatics.generated.h"

/**
 * 
 */
UCLASS()
class OVERWORLDBASE_API UOverworldStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category = "OverworldBaseStatics")
	static FVector GetMouseWorldHitLocation(const UObject* WorldContextObject);
};
