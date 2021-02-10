// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractComponent.h"


// Sets default values for this component's properties
UInteractComponent::UInteractComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
	
}

void UInteractComponent::OnHover()
{
	OnHovered.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("Hover"))
}

void UInteractComponent::ReleaseHover()
{
	OnHoverReleased.Broadcast();
}

void UInteractComponent::OnClick()
{
	ComponentClicked.Broadcast();
}


// Called every frame
void UInteractComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
