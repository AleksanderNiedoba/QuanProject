// Copyright Quan Project 2021. All Rights Reserved.


#include "QuanGameplayStatics.h"
#include "Kismet/GameplayStatics.h"
#include "QuanPlayerController.h"


AQuanPlayerController* UQuanGameplayStatics::GetQuanPlayerController(UObject* InWorldContextObject)
{
	if(auto* QPC = Cast<AQuanPlayerController>(UGameplayStatics::GetPlayerController(InWorldContextObject, 0)))
		return QPC;
	
	return nullptr; 
}
