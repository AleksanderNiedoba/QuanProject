// Copyright Quan Project 2021. All Rights Reserved.


#include "QuanActorsFactory.h"


AQuanActorsFactory::AQuanActorsFactory()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AQuanActorsFactory::BeginPlay()
{
	Super::BeginPlay();
	World = GetWorld();
}

AConstructionPreview* AQuanActorsFactory::SpawnBuildingConstruction(UObject* Caller)
{
	if(!IsValid(Caller)) return nullptr;
	
	UE_LOG(LogTemp, Log, TEXT("Spawning ConstructionPreview for caller: %s"), *Caller->GetName())
	return World->SpawnActor<AConstructionPreview>(FVector::ZeroVector, FRotator::ZeroRotator);
}

void AQuanActorsFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

