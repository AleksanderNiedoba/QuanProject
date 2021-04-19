// Copyright Quan Project 2021. All Rights Reserved.


#include "Buildings/ConstructionPreview.h"

AConstructionPreview::AConstructionPreview()
{
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>("RootCompoent");
	RootComponent = Root;
	
	BuildingMesh = CreateDefaultSubobject<UStaticMeshComponent>("BuildingMesh");
	BuildingMesh->SetupAttachment(RootComponent);

	MouseFollowComponent = CreateDefaultSubobject<UMouseFollowComponent>("FollowComponent");

	SetActorEnableCollision(false); 
}

void AConstructionPreview::BeginPlay()
{
	Super::BeginPlay();
	MouseFollowComponent->EnableActorFollowing(true);
}

void AConstructionPreview::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AConstructionPreview::InitWithData(FBuildingSettings Settings)
{
	BuildingMesh->SetStaticMesh(Settings.BuildingMesh);
	//BuildingMesh->SetMaterial(); TODO
	
}

