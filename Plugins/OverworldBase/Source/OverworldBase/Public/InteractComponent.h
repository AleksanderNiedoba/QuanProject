// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FComponentHovered);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FComponentRelesedHovere);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FComponentClicked);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class OVERWORLDBASE_API UInteractComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractComponent();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	virtual void OnHover();
	virtual void ReleaseHover();
	virtual void OnClick();

public:
	//Component events 
	UPROPERTY(BlueprintAssignable)
	FComponentHovered OnHovered;
	UPROPERTY(BlueprintAssignable)
	FComponentRelesedHovere OnHoverReleased;
	UPROPERTY(BlueprintAssignable)
	FComponentClicked ComponentClicked;
};
