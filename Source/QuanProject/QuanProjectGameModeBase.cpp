// Copyright Epic Games, Inc. All Rights Reserved.


#include "QuanProjectGameModeBase.h"
#include "OverworldCameraPawn.h"
#include "Kismet/GameplayStatics.h"
#include "QuanActorsFactory.h"
#include "OverworldPlayerController.h"

AQuanProjectGameModeBase::AQuanProjectGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	DefaultPawnClass = AOverworldCameraPawn::StaticClass();
	PlayerControllerClass = AOverworldPlayerController::StaticClass();
	BuildingSystemClass = UBuildingSystem::StaticClass();
	
}


AQuanProjectGameModeBase* AQuanProjectGameModeBase::GetQuanGamemode(const UObject* WorldContextObject)
{
	return Cast<AQuanProjectGameModeBase>(UGameplayStatics::GetGameMode(WorldContextObject));
}


void AQuanProjectGameModeBase::PreInitializeComponents()
{
	Super::PreInitializeComponents();
}

void AQuanProjectGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	
}

void AQuanProjectGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	AQuanActorsFactory* ActorsFactory = GetWorld()->SpawnActor<AQuanActorsFactory>(FVector::ZeroVector, FRotator::ZeroRotator);
	BuildingSystem = UBuildingSystem::CreateNew();
	BuildingSystem->Init(ActorsFactory); 
}
