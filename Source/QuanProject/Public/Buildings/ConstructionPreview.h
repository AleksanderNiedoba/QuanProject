// Copyright Quan Project 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/MouseFollowComponent.h"
#include "Buildings/DABuildingData.h"
#include "Buildings/BuildingBase.h"
#include "ConstructionPreview.generated.h"

UCLASS()
class QUANPROJECT_API AConstructionPreview : public AActor
{
	GENERATED_BODY()
protected:
	
public:	
	AConstructionPreview();
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	UMouseFollowComponent* MouseFollowComponent;
	UPROPERTY()
	UStaticMeshComponent* BuildingMesh;
	UPROPERTY()
	USceneComponent* Root; 
	UPROPERTY()
	TSubclassOf<ABuildingBase> BuildingClass; 
	
public:	
	virtual void Tick(float DeltaTime) override;
	void InitWithData(FBuildingSettings Settings); 
};
