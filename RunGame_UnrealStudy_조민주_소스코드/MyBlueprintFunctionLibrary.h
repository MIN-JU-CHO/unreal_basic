// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RunGameWithCPlus/GameManager.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class RUNGAMEWITHCPLUS_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION()
		static AGameManager* GetGameManagerRef(const UWorld* world);
};
