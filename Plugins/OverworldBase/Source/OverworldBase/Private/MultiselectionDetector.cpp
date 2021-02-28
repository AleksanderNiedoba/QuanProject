// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiselectionDetector.h"
#include "OverworldStatics.h"
#include "Kismet/KismetMathLibrary.h"


AMultiselectionDetector::AMultiselectionDetector()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("RootComponent");
	RootComponent = Root;
	
	StartArrow = CreateDefaultSubobject<UArrowComponent>("StartArrow");
	StartArrow->SetupAttachment(RootComponent);
	
	VertexLocation = CreateDefaultSubobject<USceneComponent>("VertexLocationSlot");
	VertexLocation->SetupAttachment(RootComponent);

	WorldLocation = CreateDefaultSubobject<USceneComponent>("WorldLocation");
	WorldLocation->SetupAttachment(RootComponent);
	
	OverlapBox = CreateDefaultSubobject<UBoxComponent>("OverlapBox");
	OverlapBox->SetupAttachment(RootComponent);

	
	OverlapBox->SetVisibility(true);
	OverlapBox->SetHiddenInGame(false);
}

void AMultiselectionDetector::BeginPlay()
{
	Super::BeginPlay();
}

void AMultiselectionDetector::UpdateMultiselectionBoxSize()
{

	const FVector MouseInWorldLocation = UOverworldStatics::GetMouseWorldHitLocation(this);
	WorldLocation->SetWorldLocation(MouseInWorldLocation);
	const FVector RelativeMouseLocation = WorldLocation->GetRelativeLocation();
	
	const FRotator NewRootRotation = UKismetMathLibrary::FindLookAtRotation(FVector::ZeroVector, RelativeMouseLocation);

	StartArrow->SetWorldRotation(NewRootRotation);
	const FVector StartLocationForwardVector = StartArrow->GetForwardVector();
	
	VertexLocation->SetRelativeLocation(FVector(0.0, RelativeMouseLocation.Y, 0.0));
	OverlapBox->SetRelativeLocation(StartLocationForwardVector*(FVector::ZeroVector - RelativeMouseLocation).Size()*0.5);
	
	const float OverlapBoxSizeY = 0.5*(VertexLocation->GetRelativeLocation()).Size();
	const float OverlapBoxSizeX = 0.5*(VertexLocation->GetRelativeLocation() - RelativeMouseLocation).Size();
	OverlapBox->SetBoxExtent(FVector(OverlapBoxSizeX,OverlapBoxSizeY,1000.0), true);
}

void AMultiselectionDetector::ScanForSelectedActors()
{
	TArray<AActor*> OverlapingActors;
	OverlapBox->GetOverlappingActors(OverlapingActors);
	InteractionHandler->RegisterMultiselectionActors(OverlapingActors);
}

void AMultiselectionDetector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateMultiselectionBoxSize();
	ScanForSelectedActors();
}

void AMultiselectionDetector::Init(UInteractionHandler* _InteractionHandler)
{
	InteractionHandler = _InteractionHandler; 
}

