#pragma once

#include "CoreMinimal.h"
#include "OverworldBaseSettings.generated.h"

UENUM()
enum class EZoomState : uint8
{
	ZommingIn,
	ZommingOut
};

UENUM()
enum class EScreenMovement : uint8
{
	Left,
	Right,
	Top,
	Bottom
};

USTRUCT()
struct FOverworldKeysSettings
{
	GENERATED_BODY()

	FKey ZoomIn		=	EKeys::MouseScrollDown;
	FKey MoveUp		=	EKeys::Up;
	FKey MoveDown	=	EKeys::Down;
	FKey MoveLeft	=	EKeys::Left;
	FKey MoveRight	=	EKeys::Right;
};