// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponent.h"
#include <RunGameWithCPlus/MyBlueprintFunctionLibrary.h>

// Sets default values for this component's properties
UMoveComponent::UMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	//생성자 함수에서는 절대 참조(GetAllActorsOfClass)하지 말자
}


// Called when the game starts
void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	//Init();
}


// Called every frame
void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (GameManagerRef != nullptr) {
		moveVec = forwardVec * GameManagerRef->SpeedRoad * DeltaTime;
		GetOwner()->AddActorLocalOffset(moveVec);
	}
}

void UMoveComponent::Init()
{
	GameManagerRef = UMyBlueprintFunctionLibrary::GetGameManagerRef(GetWorld());
	forwardVec = GetOwner()->GetActorForwardVector();
}

