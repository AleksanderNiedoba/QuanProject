// Copyright Quan Project 2021. All Rights Reserved.


#include "GameTime/GameClockComponent.h"
#include "Kismet/KismetMathLibrary.h"


UGameClockComponent::UGameClockComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UGameClockComponent::BeginPlay()
{
	Super::BeginPlay();
	//TODO Setup on start
	EnableClock(true); 
}

void UGameClockComponent::SetupClockwork(float DeltaSeconds)
{
	Clockwork += DeltaSeconds/TimeUnit;
	DayTick += UKismetMathLibrary::FMod(Clockwork, 24.f, Clockwork);
}

void UGameClockComponent::Clock()
{
	const float Time = Clockwork * 3600;
	float Reminder = 0.f;
	
	int32 TimeUnits = UKismetMathLibrary::FMod(Time, 60.f, Reminder);
	Seconds = FMath::Floor(Reminder);
	
	TimeUnits = UKismetMathLibrary::FMod(TimeUnits, 60.f, Reminder);
	Minutes = FMath::Floor(Reminder);
	
	UKismetMathLibrary::FMod(TimeUnits, 60.f, Reminder);
	Hours = FMath::Floor(Reminder);

	if(!CreateNewTimeStruct())
		return;

	OnTimeChanged.Broadcast(TimeStruct);
}

bool UGameClockComponent::CreateNewTimeStruct()
{
	const FQuanGameTime NewTimeStruct =
		{
		Seconds = this->Seconds,
		Minutes = this->Minutes,
		Hours = this->Hours,
		DayTick = this->DayTick
	};
	if (NewTimeStruct == TimeStruct)
		return false;

	TimeStruct = NewTimeStruct;
	return true; 
}

void UGameClockComponent::EnableClock(bool NewEnable)
{
	ClockEnabled = NewEnable;
}

FQuanGameTime UGameClockComponent::GetCurrentTime() const
{
	 return TimeStruct;
}

float UGameClockComponent::GetClockwork() const
{
	return Clockwork; 
}

void UGameClockComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if(ClockEnabled)
	{
		SetupClockwork(DeltaTime);
		Clock();
		
	}
}

