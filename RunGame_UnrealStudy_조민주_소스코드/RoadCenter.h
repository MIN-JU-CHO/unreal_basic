// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoadBase.h"
#include "RoadCenter.generated.h"

/**
 * 
 */
UCLASS()
class RUNGAMEWITHCPLUS_API ARoadCenter : public ARoadBase
{
	GENERATED_BODY()
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void OnConstruction(const FTransform& transform) override;

	UPROPERTY(EditAnyWhere)
		UMaterial* Black;
	UPROPERTY(EditAnyWhere)
		UMaterial* Blue;

	UPROPERTY(EditAnyWhere)
		UStaticMeshComponent* uCube;
	ARoadCenter();
};
