// Copyright Quan Project 2021. All Rights Reserved.


#include "QuanPlayerController.h"

EInteractionContext AQuanPlayerController::GetCurrentInteractionContext()
{
	return InteractionContext; 
}

void AQuanPlayerController::SetInteractionContext(EInteractionContext NewContext)
{
	InteractionContext = NewContext; 
}
