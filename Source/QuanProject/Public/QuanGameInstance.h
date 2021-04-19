// Copyright Quan Project 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DataProvider.h"
#include "QuanGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class QUANPROJECT_API UQuanGameInstance : public UGameInstance, public IDataProvider
{
	GENERATED_BODY()

	virtual void Init() override;
	
	public:
	UFUNCTION()
	virtual UQuanDataProvider* GetDataProvider() override; 
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced)
	UQuanDataProvider* DataProvider; 
};
