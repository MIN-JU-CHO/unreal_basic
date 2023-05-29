// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <RunGameWithCPlus/ControlRoadCenter.h>

#include "Components/BoxComponent.h"
#define MYLOG(Format, ...)  UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::Printf(TEXT(Format), ##__VA_ARGS__) )
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameManager.generated.h"
UCLASS()
class RUNGAMEWITHCPLUS_API AGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnConstruction(const FTransform& transform) override;

	static void MY_DEBUG(FString text);

	static void MY_SCREEN_DEBUG(FString text);

	UPROPERTY(EditAnyWhere)
		USceneComponent* uSceneComponent;
	UPROPERTY(EditAnyWhere)
		UBoxComponent* BoxCollision;
	UPROPERTY(EditAnyWhere, Category="Data")
		float ExtendWidth=100.0f;
	UPROPERTY(EditAnyWhere, Category = "Data")
		float SpeedRoad = -100.0f;	//beginplay에서 참조할 것이므로 construction에서는 필요 없음
	UFUNCTION()
		void FuncActorBegin(AActor* overlappedActor, AActor* otherActor);
	FScriptDelegate delegateOnActorBegin;


	AControlRoadCenter* RoadControlCenterRef;
};
