// Copyright Quan Project 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Buildings/ConstructionPreview.h"
#include "QuanActorsFactory.generated.h"

UCLASS()
class QUANPROJECT_API AQuanActorsFactory : public AActor
{
	GENERATED_BODY()
	
public:	
	AQuanActorsFactory();

protected:
	virtual void BeginPlay() override;
	UPROPERTY()
	UWorld* World;

public:	
	AConstructionPreview* SpawnBuildingConstruction(UObject* Caller);
	virtual void Tick(float DeltaTime) override;

};
