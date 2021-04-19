// Copyright Quan Project 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MouseFollowComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OVERWORLDBASE_API UMouseFollowComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UMouseFollowComponent();

protected:

	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void EnableActorFollowing(bool NewEnable);
private:
	bool EnableMouseFollow = false;
		
};
