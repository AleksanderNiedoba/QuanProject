#include "QuanGameState.h"


AQuanGameState::AQuanGameState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ClockComponent = CreateDefaultSubobject<UGameClockComponent>(TEXT("ClockComponent"));
}

void AQuanGameState::BeginPlay()
{
	Super::BeginPlay();
}

UGameClockComponent* AQuanGameState::GetClock() const
{
	return ClockComponent; 
}
