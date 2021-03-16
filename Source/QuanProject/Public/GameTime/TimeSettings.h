#pragma once

#include "CoreMinimal.h"
#include "TimeSettings.generated.h"

USTRUCT(BlueprintType)
struct FQuanGameTime
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int32 Seconds;
	UPROPERTY(BlueprintReadWrite)
	int32 Minutes;
	UPROPERTY(BlueprintReadWrite)
	int32 Hours;
	UPROPERTY(BlueprintReadWrite)
	int32 DayTick;

	FORCEINLINE bool operator ==(const FQuanGameTime& Other) const 
	{
		return  Seconds == Other.Seconds &&
				Minutes == Other.Minutes &&
				Hours   == Other.Hours   &&
				DayTick == Other.DayTick;
	}
};

UENUM(BlueprintType)
enum class EGameSpeed : uint8
{
	Planning,
	TurnSlow,
	TurnNormal,
	TurnFast,
	Pause
};