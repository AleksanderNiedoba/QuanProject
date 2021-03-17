// Copyright Quan Project 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConstructionPreview.generated.h"

UCLASS()
class QUANPROJECT_API AConstructionPreview : public AActor
{
	GENERATED_BODY()
	
public:	
	AConstructionPreview();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};
