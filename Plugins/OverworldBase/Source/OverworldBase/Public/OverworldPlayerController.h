// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OverworldBaseSettings.h"
#include "OverworldCameraPawn.h"
#include "InteractionHandler.h"
#include "GameFramework/PlayerController.h"
#include "OverworldPlayerController.generated.h"


UCLASS()
class OVERWORLDBASE_API AOverworldPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AOverworldPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	

	//UFUNCTION(BlueprintCallable, Category = "OverworldBase");
	void EnableCameraSpan(bool NewEnable);
	//UFUNCTION(BlueprintCallable, Category = "OverworldBase");
	void EnableCameraMove(bool NewEnable);


	void HandleCameraMove(EScreenMovement MoveDirection);
	void UpdateViewportSize();	 
	void ZoomIn();
	void ZoomOut();

	virtual void Tick(float DeltaSeconds) override;
	
	//test
	void EnableSpan();
	void DisableSpan();

protected:
	virtual void BeginPlay() override;

private:
	void SetupCameraPawn();
	void RecenterMouseCoordinates();
	void UpdateInteractions();
	void UpdateSpan();
	bool CheckEdgeMovement();
	bool CheckKeyboardMovement();

public:
	float TraceDistance = 30000;
private:
	AOverworldCameraPawn* CameraPawn;

	UPROPERTY()
	UInteractionHandler* InteractionHandler;

	int32 ViewportSizeX, ViewportSizeY;
	bool CameraSpanEnabled = false;
	bool CameraMoveEnabled = true;
	bool InteractionsEnabled = true; 
	FOverworldKeysSettings NaviButtons;
};
