// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OverworldBaseSettings.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Pawn.h"
#include "OverworldCameraPawn.generated.h"

UCLASS()
class OVERWORLDBASE_API AOverworldCameraPawn : public APawn
{
	GENERATED_BODY()

public:
	AOverworldCameraPawn();

	//Defaults

public:

	const float DefaultSpringArmLength = 10000.0;
	const float MaxZoomDistance = 30000.0;
	const float MinZoomDistance = 4000.0;
	const float CameraSpeedMultiplier = 50.0;
	const float CameraZoomSpeedMultiplier = 0.1;
	const float MaxVerticalSpan = -20;
	const float MinVerticalSpan = -75.0;

	const FRotator DefaultCameraRotation = FRotator(-30.0, 0.0, 0.0);
private:

	float DestZoomDistance;
	bool NeedZoomUpdate;

public:
	//Camera Components 
	UPROPERTY()
	USceneComponent* CameraRootComponent;
	UPROPERTY()
	USceneComponent* HorizontalSpanRoot;
	UPROPERTY()
	USceneComponent* VerticalSpanRoot;
	UPROPERTY(BlueprintReadWrite)
	UCameraComponent* CameraComponent;
	UPROPERTY()
	USpringArmComponent* CameraSpringArm;

protected:
	virtual void BeginPlay() override;

	void SetupCameraDefaults();
	void UpdateZoomDistance();

public:	
	virtual void Tick(float DeltaTime) override;
	void MoveCamera(const EScreenMovement Direction);
	void AdjustCameraSpan(const float MouseX, const float MouseY) const;
	void RequestZoomChange(const EZoomState ZoomState);
};
