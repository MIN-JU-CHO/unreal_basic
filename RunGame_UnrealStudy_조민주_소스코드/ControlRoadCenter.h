// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ControlRoadCenter.generated.h"

UCLASS()
class RUNGAMEWITHCPLUS_API AControlRoadCenter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AControlRoadCenter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	AActor* LastRoadCenter;
	void ReSpawnActor(AActor* OtherActor);
};
