// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionHandler.h"

void UInteractionHandler::FindInteractions(FHitResult HitResult)
{
	if (HitResult.Actor == nullptr)
	{
		CheckForRelease();
		return; 
	}

	if (UInteractComponent* InteractComponent = HitResult.Actor->FindComponentByClass<UInteractComponent>())
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
