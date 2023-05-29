// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RunGameWithCPlus/MoveComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoadBase.generated.h"

UCLASS()
class RUNGAMEWITHCPLUS_API ARoadBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoadBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnyWhere)
		USceneComponent* uSceneComponent;

	UPROPERTY(EditAnyWhere)
		UStaticMeshComponent* uStaticMeshComponent;
	UPROPERTY(EditAnyWhere)
		UMoveComponent* uMoveComponent;
};
