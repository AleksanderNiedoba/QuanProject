// Copyright Quan Project 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Misc/TypeContainer.h"
#include "BuildingDataTable.h"
#include "QuanDataProvider.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), DefaultToInstanced, EditInlineNew)
class QUANPROJECT_API UQuanDataProvider : public UObject
{
	GENERATED_BODY()
	
	public:
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBuildingDataTable* Buildings = nullptr;

	UFUNCTION(BlueprintPure, meta = (WorldContext = "InWorldContextObject"), Category = "QuanData")
	static UQuanDataProvider* GetQuanDataProvider(UObject* InWorldContextObject);

	UFUNCTION(BlueprintCallable)
	TArray<UDABuildingData*> GetAllBuildingData();

	UFUNCTION()
	void LoadGameData() const;
	
};
