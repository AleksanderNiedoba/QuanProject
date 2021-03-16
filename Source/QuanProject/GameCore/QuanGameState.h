// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "GameTime/GameClockComponent.h"
#include "QuanGameState.generated.h"


UCLASS()
class QUANPROJECT_API AQuanGameState : public AGameStateBase
{
	GENERATED_BODY()
	
	AQuanGameState(const FObjectInitializer&);
	
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Time")
	UGameClockComponent* ClockComponent;
	
protected:
	
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintPure)
	UGameClockComponent* GetClock() const;
};


