// Copyright Quan Project 2021. All Rights Reserved.


#include "BuildingDataTable.h"

void UBuildingDataTable::LoadDataAssets()
{
	BuildingsData.Empty();
	for(auto SoftBuilding : BuildingDataTable)
	{
		BuildingsData.AddUnique(SoftBuilding.LoadSynchronous());
	}
}
