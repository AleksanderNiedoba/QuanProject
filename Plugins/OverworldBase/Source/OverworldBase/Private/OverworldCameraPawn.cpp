// Fill out your copyright notice in the Description page of Project Settings.


#include "OverworldCameraPawn.h"

// Sets default values
AOverworldCameraPawn::AOverworldCameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraRootComponent = CreateDefaultSubobject<USceneComponent>("CameraRootComponent");
	CameraRootComponent->SetupAttachment(RootComponent);
	RootComponent = CameraRootComponent;

	HorizontalSpanRoot = CreateDefaultSubobject<USceneComponent>("HorizontalSpanRoot");
	HorizontalSpanRoot->SetupAttachment(CameraRootComponent);

	VerticalSpanRoot = CreateDefaultSubobject<USceneComponent>("VerticalSpanRoot");
	VerticalSpanRoot->SetupAttachment(HorizontalSpanRoot);

	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>("CameraSpringArm");
	CameraSpringArm->SetupAttachment(VerticalSpanRoot);


	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(CameraSpringArm);

	SetupCameraDefaults();

}

// Called when the game starts or when spawned
void AOverworldCameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOverworldCameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (NeedZoomUpdate) {
		UpdateZoomDistance();
	}

}

void AOverworldCameraPawn::SetupCameraDefaults()
{
	DestZoomDistance = DefaultSpringArmLength;
	CameraSpringArm->TargetArmLength = DefaultSpringArmLength;
	VerticalSpanRoot->SetRelativeRotation(DefaultCameraRotation);
}

void AOverworldCameraPawn::UpdateZoomDistance()
{
	float CurrentZoomDistance = CameraSpringArm->TargetArmLength;

	if (CurrentZoomDistance != DestZoomDistance)
	{
		if (abs(DestZoomDistance - CurrentZoomDistance) <= CameraZoomSpeedMultiplier)
		{
			CameraSpringArm->TargetArmLength = DestZoomDistance;
			NeedZoomUpdate = false;
			return;
		}
		CurrentZoomDistance = FMath::Lerp(CurrentZoomDistance, DestZoomDistance, CameraZoomSpeedMultiplier);
		CameraSpringArm->TargetArmLength = CurrentZoomDistance;
	}
}



void AOverworldCameraPawn::MoveCamera(EScreenMovement Direction)
{
	FVector CurrentLocation = GetActorLocation();
	FVector NewLocation;
	FVector ForwardMoveVector = HorizontalSpanRoot->GetForwardVector();
	FVector RightMoveVector = HorizontalSpanRoot->GetRightVector();

	switch (Direction)
	{
	case EScreenMovement::Bottom:
		NewLocation = CurrentLocation - ForwardMoveVector * CameraSpeedMultiplier;
		break;
	case EScreenMovement::Top:
		NewLocation = CurrentLocation + ForwardMoveVector * CameraSpeedMultiplier;
		break;
	case EScreenMovement::Right:
		NewLocation = CurrentLocation + RightMoveVector * CameraSpeedMultiplier;
		break;
	case EScreenMovement::Left:
		NewLocation = CurrentLocation - RightMoveVector * CameraSpeedMultiplier;
		break;
	}

	SetActorLocation(NewLocation);
}

void AOverworldCameraPawn::AdjustCameraSpan(float MouseX, float MouseY)
{
	if (abs(MouseX) > 0)
	{
		HorizontalSpanRoot->AddRelativeRotation(FRotator(0.0, MouseX, 0.0));
	}
	if (abs(MouseY) > 0)
	{
		float CurrentVerticalRotation = VerticalSpanRoot->GetRelativeRotation().Pitch;
		float NewVerticalRotation = FMath::Clamp(CurrentVerticalRotation + MouseY, MinVerticalSpan, MaxVerticalSpan);
		VerticalSpanRoot->SetRelativeRotation(FRotator(NewVerticalRotation, 0.0, 0.0));
	}
}

void AOverworldCameraPawn::RequestZoomChange(EZoomState ZoomState)
{
	float PrevoiusZoomDistance = DestZoomDistance;

	switch (ZoomState)
	{
	case EZoomState::ZommingIn:
		DestZoomDistance = FMath::Clamp(DestZoomDistance += 1000, MinZoomDistance, MaxZoomDistance);
		break;
	case EZoomState::ZommingOut:
		DestZoomDistance = FMath::Clamp(DestZoomDistance -= 1000, MinZoomDistance, MaxZoomDistance);
		break;
	}
	if (PrevoiusZoomDistance != DestZoomDistance)
		NeedZoomUpdate = true;
}



