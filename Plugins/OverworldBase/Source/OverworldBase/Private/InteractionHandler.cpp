// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionHandler.h"
#include "OverworldStaticEvents.h"

void UInteractionHandler::UpdateInteractions(FHitResult HitData)
{
	if (HitData.Actor == nullptr)
	{
		CheckForRelease();
		return; 
	}

	if (UInteractComponent* NewHoveredComponent = HitData.Actor->FindComponentByClass<UInteractComponent>())
	{
		if (NewHoveredComponent != HoveredComponent)
		{
			CheckForRelease();
			HoveredComponent = NewHoveredComponent;
			HoveredComponent->Hover();
		}
		return; 
	}
	CheckForRelease();
}

void UInteractionHandler::RegisterMultiselectionActors(TArray<AActor*> OverlapingActors)
{
	TArray<UInteractComponent*> NotSelectedComponents = MultiselectedComponents;
	for (AActor* OverlapedActor : OverlapingActors)
	{
		UInteractComponent* InteractComponent = OverlapedActor->FindComponentByClass<UInteractComponent>();
		if (InteractComponent == nullptr) continue; 

		if(MultiselectedComponents.Find(InteractComponent) == INDEX_NONE)
		{
			MultiselectedComponents.Add(InteractComponent);
			InteractComponent->MultiselectionHover();
		}
		else
		{
			NotSelectedComponents.Remove(InteractComponent);
		}
	}

	for(UInteractComponent* OldComponent : NotSelectedComponents)
	{
		MultiselectedComponents.Remove(OldComponent);
		OldComponent->MultiselectionRelease();
	}
	
}

void UInteractionHandler::HandleMultiselectionEnd()
{
	//TODO: On release multiselection handle actors selection. Temp release 
	ReleaseMultiselectHovers();
}

void UInteractionHandler::Init()
{
	UOverworldStaticEvents::OnContextChanged.AddDynamic(this, &UInteractionHandler::UpdateInteractionContext);
}

void UInteractionHandler::ReleaseMultiselectHovers()
{
	for(UInteractComponent* InteractComponent : MultiselectedComponents)
	{
		InteractComponent->ReleaseHover();
	}
	MultiselectedComponents.Empty();
}

void UInteractionHandler::CheckForRelease()
{
	if(HoveredComponent)
	{
		HoveredComponent->ReleaseHover();
		HoveredComponent = nullptr; 
	}
}

void UInteractionHandler::UpdateInteractionContext(EInteractionContext NewContext)
{
	if(NewContext != EInteractionContext::Free)
		CheckForRelease();
}
