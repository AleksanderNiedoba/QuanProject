// Copyright Quan Project 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/InteractComponent.h"
#include "BuildingBase.generated.h"

UCLASS()
class QUANPROJECT_API ABuildingBase : public AActor
{
	GENERATED_BODY()

public:	
	ABuildingBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	
	virtual void BuildingConstructed();
	virtual void BuildingDestroyed();

	UFUNCTION(BlueprintImplementableEvent, Category = "Building")
	void OnBuildingConstructed();
	UFUNCTION(BlueprintImplementableEvent, Category = "Building")
	void OnBuildingDestroyed();

};
