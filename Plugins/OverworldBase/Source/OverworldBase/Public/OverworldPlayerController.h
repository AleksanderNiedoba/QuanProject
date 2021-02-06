// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OverworldBaseSettings.h"
#include "OverworldCameraPawn.h"
#include "GameFramework/PlayerController.h"
#include "OverworldPlayerController.generated.h"


UCLASS()
class OVERWORLDBASE_API AOverworldPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AOverworldPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	

	void HandleCameraMove(EScreenMovement MoveDirection);
	void EnableCameraSpan(bool NewEnable);
	void EnableCameraMove(bool NewEnable);
	void UpdateViewportSize();	 
	void ZoomIn();
	void ZoomOut();

	virtual void Tick(float DeltaSeconds) override;

protected:
	virtual void BeginPlay() override;

private:
	void SetupCameraPawn();
	void RecenterMouseCoordinates();
	void UpdateSpan();
	bool CheckEdgeMovement();
	bool CheckKeyboardMovment();


private:
	AOverworldCameraPawn* CameraPawn;

	int32 ViewportSizeX, ViewportSizeY;
	bool CameraSpanEnabled = false;
	bool CameraMoveEnabled = true;

	FOverworldKeysSettings NaviButtons;
};
