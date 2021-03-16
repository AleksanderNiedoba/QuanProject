// Copyright Quan Project 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameTime/TimeSettings.h"
#include "GameClockComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTimeChanged, FQuanGameTime, NewTime);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class QUANPROJECT_API UGameClockComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGameClockComponent();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Time")
	float TimeUnit = 3600.f;

	UPROPERTY(BlueprintAssignable)
	FTimeChanged OnTimeChanged;

protected:
	virtual void BeginPlay() override;

	void SetupClockwork(float DeltaSeconds);
	void Clock();
	bool CreateNewTimeStruct();

	bool ClockEnabled = false;
	float Clockwork = 0.f;
	int32 Seconds, Minutes, Hours;
	int32 DayTick = 0;
	FQuanGameTime TimeStruct;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void EnableClock(bool NewEnable);

	UFUNCTION(BlueprintPure, Category = "Time")
	FQuanGameTime GetCurrentTime() const;

	UFUNCTION(BlueprintPure, Category = "Time")
    float GetClockwork() const;
};



