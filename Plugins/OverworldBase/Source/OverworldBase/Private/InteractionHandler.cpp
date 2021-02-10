// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionHandler.h"
#include "OverworldStatics.h"

void UInteractionHandler::UpdateInteractions(FHitResult HitData)
{
	if (HitData.Actor == nullptr)
	{
		CheckForRelease();
		return; 
	}

	if (UInteractComponent* InteractComponent = HitData.Actor->FindComponentByClass<UInteractComponent>())
	{
		if (InteractComponent != HoveredComponent)
		{
			CheckForRelease();
			HoveredComponent = InteractComponent;
			InteractComponent->OnHover();
		}
		return; 
	}
	CheckForRelease();
}

void UInteractionHandler::CheckForRelease()
{
	if (HoveredComponent){
		HoveredComponent->ReleaseHover();
		HoveredComponent = nullptr;
	}
}
