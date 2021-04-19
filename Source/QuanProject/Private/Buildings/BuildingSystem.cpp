// Copyright Quan Project 2021. All Rights Reserved.


#include "Buildings/BuildingSystem.h"
#include "Buildings/DABuildingData.h"
#include "QuanGameplayStatics.h"
#include "QuanPlayerController.h"
#include "QuanProject/QuanProjectGameModeBase.h"


UBuildingSystem* UBuildingSystem::CreateNew()
{
	auto* Instance = NewObject<UBuildingSystem>(); 
	return Instance;
}

void UBuildingSystem::Init(AQuanActorsFactory* Factory)
{
	ActorsFactory = Factory; 
}


UBuildingSystem* UBuildingSystem::GetBuildingSystem(UObject* InWorldContextObject)
{
	if (auto GM = AQuanProjectGameModeBase::GetQuanGamemode(InWorldContextObject))
	{
		return GM->BuildingSystem;
	}
	return nullptr;
}

void UBuildingSystem::InvalidateConstruction()
{
	if(!IsValid(ConstructionPreview)) return;
	
	ConstructionPreview->Destroy();
	DurningConstruction = false; 
	auto* PlayerController = UQuanGameplayStatics::GetQuanPlayerController(ActorsFactory);
	if (!IsValid(PlayerController)) return;
	PlayerController->SetInteractionContext(EInteractionContext::Free);
}


void UBuildingSystem::TryConstructBuilding(UDABuildingData* BuildingData)
{
	auto* PlayerController = UQuanGameplayStatics::GetQuanPlayerController(ActorsFactory);
	if (!IsValid(PlayerController)) return;
	if (PlayerController->GetCurrentInteractionContext() != EInteractionContext::Free &&
		PlayerController->GetCurrentInteractionContext() != EInteractionContext::Construction)
			return;

	if(DurningConstruction)
	{
		ConstructionPreview->Destroy();
		ConstructionPreview = ActorsFactory->SpawnBuildingConstruction(this);
		ConstructionPreview->InitWithData(BuildingData->GetBuildingSettings());
		return;
	}
	
	
	PlayerController->SetInteractionContext(EInteractionContext::Construction);
	const FVector SpawnLocation = PlayerController->GetMouseHitLocation(); 
	
	ConstructionPreview = ActorsFactory->SpawnBuildingConstruction(this);
	ConstructionPreview->InitWithData(BuildingData->GetBuildingSettings()); 
	DurningConstruction = true; 
}


 