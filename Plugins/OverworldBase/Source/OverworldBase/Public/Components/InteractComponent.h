// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FComponentHovered);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FComponentRelesedHover);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FComponentMulticelectionHover);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FComponentMulticelectionRelease);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FComponentClicked);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class OVERWORLDBASE_API UInteractComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInteractComponent();

	//Component events 
	UPROPERTY(BlueprintAssignable)
	FComponentHovered OnHovered;
	UPROPERTY(BlueprintAssignable)
	FComponentRelesedHover OnHoverReleased;
	UPROPERTY(BlueprintAssignable)
	FComponentClicked ComponentClicked;
	UPROPERTY(BlueprintAssignable)
	FComponentMulticelectionHover OnMultiselectionHover;
	UPROPERTY(BlueprintAssignable)
	FComponentMulticelectionRelease OnMultiselectionRelease; 

protected:
	virtual void BeginPlay() override;


public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	virtual void Hover();
	virtual void ReleaseHover();
	virtual void MultiselectionHover();
	virtual void MultiselectionRelease();
	virtual void Click();
	
};
