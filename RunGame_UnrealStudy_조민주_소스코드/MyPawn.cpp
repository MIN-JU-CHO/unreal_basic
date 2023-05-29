// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "RunGameWithCPlus/GameManager.h"

#include "RunGameWithCPlus/MyBlueprintFunctionLibrary.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MYLOG("AMyPawn::AMyPawn");
	AGameManager::MY_DEBUG(TEXT("AMyPawn::AMyPawn"));
	AGameManager::MY_SCREEN_DEBUG(TEXT("AMyPawn::AMyPawn"));
	AGameManager::MY_DEBUG(FString::Printf(TEXT("%d"), 10000));
	AGameManager::MY_SCREEN_DEBUG(TEXT("AMyPawn::AMyPawn"));

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	AGameManager::MY_SCREEN_DEBUG("SetupPlayerInputComponent");
	PlayerInputComponent->BindAction("LEFT", IE_Pressed, this, &AMyPawn::OnClickLeft);
	PlayerInputComponent->BindAction("RIGHT", IE_Pressed, this, &AMyPawn::OnClickRight);

}

void AMyPawn::OnClickLeft()
{

	AGameManager::MY_SCREEN_DEBUG(TEXT("OnClickLeft"));
}

void AMyPawn::OnClickRight()
{
	AGameManager::MY_SCREEN_DEBUG(TEXT("OnClickRight"));

	AGameManager* GameManagerRef = UMyBlueprintFunctionLibrary::GetGameManagerRef(GetWorld());
	
	AGameManager::MY_SCREEN_DEBUG(FString::Printf(TEXT("%f"), GameManagerRef->SpeedRoad));
}

