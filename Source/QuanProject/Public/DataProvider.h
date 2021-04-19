// Copyright Quan Project 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "QuanDataProvider.h"
#include "DataProvider.generated.h"


UINTERFACE(MinimalAPI)
class UDataProvider : public UInterface
{
	GENERATED_BODY()
};


class QUANPROJECT_API IDataProvider
{
	GENERATED_BODY()

public:
	virtual UQuanDataProvider* GetDataProvider() = 0;
};
