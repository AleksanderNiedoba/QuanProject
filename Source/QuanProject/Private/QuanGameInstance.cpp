// Copyright Quan Project 2021. All Rights Reserved.


#include "QuanGameInstance.h"

void UQuanGameInstance::Init()
{
	Super::Init();
	DataProvider->LoadGameData(); 
}

UQuanDataProvider* UQuanGameInstance::GetDataProvider()
{
	return DataProvider; 
}
