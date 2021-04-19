// Copyright Quan Project 2021. All Rights Reserved.


#include "Buildings/BuildingBase.h"



ABuildingBase::ABuildingBase()
{
	PrimaryActorTick.bCanEverTick = true;
	InteractComponent = CreateDefaultSubobject<UInteractComponent>("InteractComponent");
}


void ABuildingBase::BeginPlay()
{
	Super::BeginPlay();
}


void ABuildingBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABuildingBase::BuildingConstructed()
{
}

void ABuildingBase::BuildingDestroyed()
{
}

