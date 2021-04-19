// Copyright Quan Project 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "QuanGameplayStatics.generated.h"


UCLASS()
class QUANPROJECT_API UQuanGameplayStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	public:
	UFUNCTION(BlueprintPure, Category = "OverworldBaseStatics")
	static class AQuanPlayerController* GetQuanPlayerController(UObject* InWorldContextObject);
	
};
