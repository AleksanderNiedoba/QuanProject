// Fill out your copyright notice in the Description page of Project Settings.


#include "OverworldPlayerController.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/PlayerInput.h"


AOverworldPlayerController::AOverworldPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;

}


void AOverworldPlayerController::BeginPlay()
{
	Super::BeginPlay();
	SetupCameraPawn();
	UpdateViewportSize();
	InteractionHandler = NewObject<UInteractionHandler>();
	
	//test purposes
	InputComponent->BindAction("ZoomIn", IE_Released, this, &AOverworldPlayerController::ZoomIn);
	InputComponent->BindAction("ZoomOut", IE_Released, this, &AOverworldPlayerController::ZoomOut);
	InputComponent->BindAction("CameraSpan", IE_Pressed, this, &AOverworldPlayerController::EnableSpan);
	InputComponent->BindAction("CameraSpan", IE_Released, this, &AOverworldPlayerController::DisableSpan);
}

void AOverworldPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	FindNewMouseWorldData();
	InteractionHandler->UpdateInteractions(HitData);
	
	if (!CheckKeyboardMovement()) { 
		CheckEdgeMovement();
	}

	if (CameraSpanEnabled){
		UpdateSpan();
	}
}

void AOverworldPlayerController::EnableSpan()
{
	EnableCameraSpan(true);
}

void AOverworldPlayerController::DisableSpan()
{
	EnableCameraSpan(false);
}

void AOverworldPlayerController::HandleCameraMove(EScreenMovement MoveDirection)
{
	if (CameraMoveEnabled){
		CameraPawn->MoveCamera(MoveDirection);
	}
}

void AOverworldPlayerController::EnableCameraSpan(bool NewEnable)
{
	if(NewEnable)
	{
		GetMousePosition(LastMouseX, LastMouseY);
		bShowMouseCursor = false;
		CameraSpanEnabled = true;
	}
	else
	{
		bShowMouseCursor = true;
		CameraSpanEnabled = false;
	}
	
	bShowMouseCursor = !NewEnable;
}

void AOverworldPlayerController::EnableCameraMove(bool NewEnable)
{
	CameraMoveEnabled = NewEnable;
}

void AOverworldPlayerController::UpdateViewportSize()
{
	GetViewportSize(ViewportSizeX, ViewportSizeY);
}

void AOverworldPlayerController::ZoomIn()
{
	CameraPawn->RequestZoomChange(EZoomState::ZommingIn);
}

void AOverworldPlayerController::ZoomOut()
{
	CameraPawn->RequestZoomChange(EZoomState::ZommingOut);
}

void AOverworldPlayerController::SetupCameraPawn()
{
	CameraPawn = Cast<AOverworldCameraPawn>(GetPawn());
}

void AOverworldPlayerController::RecenterMouseCoordinates()
{
	SetMouseLocation(LastMouseX, LastMouseY);
}

void AOverworldPlayerController::FindNewMouseWorldData()
{
	FVector TraceStartLocation, TraceDirection;
	DeprojectMousePositionToWorld(TraceStartLocation, TraceDirection);
	GetWorld()->LineTraceSingleByChannel(HitData, 
		TraceStartLocation,
		TraceStartLocation + (TraceDirection * TraceDistance),
		ECollisionChannel::ECC_WorldStatic);
}

void AOverworldPlayerController::UpdateSpan()
{
	float MouseX, MouseY;
	RecenterMouseCoordinates();
	GetInputMouseDelta(MouseX, MouseY);
	CameraPawn->AdjustCameraSpan(MouseX, MouseY);
}

bool AOverworldPlayerController::CheckEdgeMovement()
{
	bool HasInput= false;
	float CurrentMouseLocationX, CurrentMouseLocationY;
	GetMousePosition(CurrentMouseLocationX, CurrentMouseLocationY);

	if (CurrentMouseLocationX / ViewportSizeX >= 0.95){
		HandleCameraMove(EScreenMovement::Right);
		HasInput = true;
	}
	if (CurrentMouseLocationX / ViewportSizeX <= 0.05){
		HandleCameraMove(EScreenMovement::Left);
		HasInput = true;
	}
	if (CurrentMouseLocationY / ViewportSizeY >= 0.95){
		HandleCameraMove(EScreenMovement::Bottom);
		HasInput = true;
	}
	if (CurrentMouseLocationY / ViewportSizeY <= 0.05){
		HandleCameraMove(EScreenMovement::Top);
		HasInput = true;
	}
	return HasInput;
}

bool AOverworldPlayerController::CheckKeyboardMovement()
{
	bool HasInput = false;
	
	if (PlayerInput)
	{
		if (PlayerInput->GetKeyValue(NaviButtons.MoveUp) > 0.0)   {
			HandleCameraMove(EScreenMovement::Top);
			HasInput = true;
		}
		if (PlayerInput->GetKeyValue(NaviButtons.MoveDown) > 0.0) {
			HandleCameraMove(EScreenMovement::Bottom);
			HasInput = true;
		}
		if (PlayerInput->GetKeyValue(NaviButtons.MoveRight) > 0.0){
			HandleCameraMove(EScreenMovement::Right);
			HasInput = true;
		}
		if (PlayerInput->GetKeyValue(NaviButtons.MoveLeft) > 0.0) {
			HandleCameraMove(EScreenMovement::Left);
			HasInput = true;
		}
	}
	return HasInput;
}

void AOverworldPlayerController::GetMouseDelta(float& MouseX, float& MouseY)
{
}

FVector AOverworldPlayerController::GetMouseHitLocation()
{
	return HitData.Location;
}
