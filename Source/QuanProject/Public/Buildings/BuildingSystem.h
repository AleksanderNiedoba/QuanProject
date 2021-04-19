// Copyright Quan Project 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "QuanActorsFactory.h"
#include "BuildingSystem.generated.h"

class UDABuildingData; 

UCLASS()
class QUANPROJECT_API UBuildingSystem : public UObject
{
	GENERATED_BODY()

	public:
	static UBuildingSystem* CreateNew();

	void Init(AQuanActorsFactory* Factory);

	UFUNCTION(BlueprintPure, meta = (WorldContext = "InWorldContextObject"), Category = "BuildingSystem")
	static UBuildingSystem* GetBuildingSystem(UObject* InWorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "BuildingSystem")
	void InvalidateConstruction();

	UFUNCTION(BlueprintCallable)
	void TryConstructBuilding(UDABuildingData* BuildingData);

	private:
	bool DurningConstruction = false;

	UPROPERTY()
	AQuanActorsFactory* ActorsFactory;

	UPROPERTY()
	class AConstructionPreview* ConstructionPreview;
};
