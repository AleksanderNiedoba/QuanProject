// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OverworldBaseSettings.h"
#include "OverworldStaticEvents.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractContextChanged, EInteractionContext, NewContext);

UCLASS()
class OVERWORLDBASE_API UOverworldStaticEvents : public UObject
{
	GENERATED_BODY()
	
public:
	static FInteractContextChanged OnContextChanged; 
};
