// Copyright Quan Project 2021. All Rights Reserved.


#include "Components/InteractComponent.h"

UInteractComponent::UInteractComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}



void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UInteractComponent::Hover()
{
	OnHovered.Broadcast();
}

void UInteractComponent::ReleaseHover()
{
	OnHoverReleased.Broadcast();
}

void UInteractComponent::MultiselectionHover()
{
	OnMultiselectionHover.Broadcast();
}

void UInteractComponent::MultiselectionRelease()
{
	OnMultiselectionRelease.Broadcast();
}

void UInteractComponent::Click()
{
	ComponentClicked.Broadcast();
}

void UInteractComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

