// Copyright Quan Project 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Buildings/BuildingBase.h"
#include "DABuildingData.generated.h"

USTRUCT(BlueprintType)
struct FBuildingSettings
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float BuildingHitPoints = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMesh* BuildingMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ABuildingBase> BuildingClass; 
};

UCLASS(BlueprintType)
class QUANPROJECT_API UDABuildingData : public UDataAsset
{
	GENERATED_BODY()
	
	public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "BuildingData")
	FText BuildingName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "BuildingData")
	FText BuildingDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "BuildingData")
	FBuildingSettings BuildingSettings;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "BuildingData")
	UTexture2D* BuildingImage;

	//Time in game minutes to construct building
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Construction")
	float ConstructionTime; 
	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "BuildingRequairements")
	//Resoursce Struct with count

	public:
	UFUNCTION(BlueprintPure)
	FBuildingSettings GetBuildingSettings();
};

