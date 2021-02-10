// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/MouseFollowComponent.h"
#include "OverworldStatics.h"


UMouseFollowComponent::UMouseFollowComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMouseFollowComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


void UMouseFollowComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if(EnableMouseFollow)
	{
		const FVector HitLocation = UOverworldStatics::GetMouseWorldHitLocation(this);
		GetOwner()->SetActorLocation(HitLocation);
		
	}	
}

void UMouseFollowComponent::EnableActorFollowing(bool NewEnable)
{
	GetOwner()->SetActorEnableCollision(!NewEnable);
	EnableMouseFollow = NewEnable;
}

