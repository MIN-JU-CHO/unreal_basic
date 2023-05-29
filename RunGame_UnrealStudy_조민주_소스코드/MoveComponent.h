// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <RunGameWithCPlus/GameManager.h>
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoveComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RUNGAMEWITHCPLUS_API UMoveComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoveComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
		FVector moveVec;
	UPROPERTY(EditAnywhere)
		FVector forwardVec;
	UPROPERTY(EditAnywhere)
		AGameManager* GameManagerRef=nullptr;

	void Init();
		
};
