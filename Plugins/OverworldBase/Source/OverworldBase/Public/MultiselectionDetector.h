// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractionHandler.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "MultiselectionDetector.generated.h"

UCLASS()
class OVERWORLDBASE_API AMultiselectionDetector : public AActor
{
	GENERATED_BODY()
	
public:
	
	AMultiselectionDetector();
	UPROPERTY()
	UArrowComponent* StartArrow;
	UPROPERTY()
	USceneComponent* Root;
	UPROPERTY()
	USceneComponent* WorldLocation;
	UPROPERTY()
	USceneComponent* VertexLocation;
	UPROPERTY()
	UBoxComponent* OverlapBox;
protected:
	int PreviousArraySize = 0;
	
	UPROPERTY()
	UInteractionHandler* InteractionHandler;
	UPROPERTY()
	FTimerHandle DetectionTimerHandle;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Init(UInteractionHandler* _InteractionHandler);

	protected:

	virtual void BeginPlay() override;
	void UpdateMultiselectionBoxSize();
	void ScanForSelectedActors();
};
