// Copyright Quan Project 2021. All Rights Reserved.


#include "QuanDataProvider.h"
#include "DataProvider.h"

UQuanDataProvider* UQuanDataProvider::GetQuanDataProvider(UObject* InWorldContextObject)
{
	if(InWorldContextObject)
	{
		if (auto* DataInterface = Cast<IDataProvider>(InWorldContextObject->GetWorld()->GetGameInstance()))
		{
			return DataInterface->GetDataProvider(); 
		}
		UE_LOG(LogTemp, Warning, TEXT("Couldnt return DataProvider instance for object: %s"), *InWorldContextObject->GetName())
	}
	
	return nullptr; 
}

TArray<UDABuildingData*> UQuanDataProvider::GetAllBuildingData()
{
	return  Buildings->BuildingsData;
}

void UQuanDataProvider::LoadGameData() const 
{
	Buildings->LoadDataAssets();
}

