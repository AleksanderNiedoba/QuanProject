// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OverworldBaseSettings.h"
#include "OverworldCameraPawn.h"
#include "InteractionHandler.h"
#include "MultiselectionDetector.h"
#include "IPlayerController.h"
#include "GameFramework/PlayerController.h"
#include "OverworldPlayerController.generated.h"


UCLASS()
class OVERWORLDBASE_API AOverworldPlayerController : public APlayerController, public IIPlayerController
{
	GENERATED_BODY()

public:
	AOverworldPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	

	UFUNCTION(BlueprintCallable, Category = "OverworldBase")
	void EnableCameraSpan(bool NewEnable);
	UFUNCTION(BlueprintCallable, Category = "OverworldBase")
	void EnableCameraMove(bool NewEnable);
	UFUNCTION(BlueprintCallable, Category = "OverworldBase")
	void StartMultiselection();
	UFUNCTION(BlueprintCallable, Category = "OverworldBase")
    void EndMultiselection();
	UFUNCTION(BlueprintCallable, Category = "OverworldBase")
	void CreateZoomRequest(EZoomState RequestState);

	void HandleCameraMove(EScreenMovement MoveDirection);	 

	virtual void Tick(float DeltaSeconds) override;
	virtual void GetMouseDelta(float& MouseX, float& MouseY) override;
	virtual  FVector GetMouseHitLocation() override;
	

protected:
	virtual void BeginPlay() override;

private:
	void SetupCameraPawn();
	void RecenterMouseCoordinates();
	void FindNewMouseWorldData();
	void UpdateSpan();
	bool CheckEdgeMovement();
	bool CheckKeyboardMovement();
	

public:
	float TraceDistance = 30000;
	EInteractionContext InteractionContext; 
private:
	UPROPERTY()
	AOverworldCameraPawn* CameraPawn;
	UPROPERTY()
	UInteractionHandler* InteractionHandler;
	UPROPERTY()
	AMultiselectionDetector* MultiselectionDetector = nullptr;
	
	FHitResult HitData;
	int32 ViewportSizeX, ViewportSizeY;
	float LastMouseX, LastMouseY;
	bool CameraSpanEnabled = false;
	bool CameraMoveEnabled = true;
	bool SingleInteractionsEnabled = true;
	FOverworldKeysSettings NaviButtons;
};
