// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Buildings/BuildingSystem.h"
#include "QuanProjectGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class QUANPROJECT_API AQuanProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()


	AQuanProjectGameModeBase(const FObjectInitializer&);
	
public:

	static AQuanProjectGameModeBase* GetQuanGamemode(const UObject* WorldContextObject);

	UPROPERTY(Transient)
	UBuildingSystem* BuildingSystem = nullptr; 

	protected:
	TSubclassOf<UBuildingSystem> BuildingSystemClass;

	virtual void PreInitializeComponents() override;
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage);
	virtual void BeginPlay() override;
};
