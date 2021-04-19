// Copyright Quan Project 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Buildings/DABuildingData.h"
#include "BuildingDataTable.generated.h"

/**
 * 
 */
UCLASS()
class QUANPROJECT_API UBuildingDataTable : public UDataAsset
{
	GENERATED_BODY()

public:

	void LoadDataAssets();
	
	UPROPERTY(EditAnywhere, Category = "BuildingData")
	TArray<TSoftObjectPtr<UDABuildingData>> BuildingDataTable;

	UPROPERTY()
	TArray<UDABuildingData*> BuildingsData; 
};
