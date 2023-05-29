// Fill out your copyright notice in the Description page of Project Settings.


#include "ControlRoadCenter.h"
#include <RunGameWithCPlus/RoadCenter.h>

// Sets default values
AControlRoadCenter::AControlRoadCenter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AControlRoadCenter::BeginPlay()
{
	Super::BeginPlay();

    UWorld* world = GetWorld();

    FActorSpawnParameters fsp;
    fsp.Owner = this;

    FVector vec = FVector::ZeroVector;
    FRotator rot = FRotator::ZeroRotator;

    
    if (world) {
        for (int i = 0; i < 5; i++)
        {
            vec.X = 1000 * i;
            ARoadCenter* roadCenter = world->SpawnActor<ARoadCenter>(ARoadCenter::StaticClass(), vec, rot, fsp);

            if (i == 4) {
                LastRoadCenter = roadCenter;
            }
        }
      }

}

// Called every frame
void AControlRoadCenter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AControlRoadCenter::ReSpawnActor(AActor* OtherActor)
{

    FVector location = LastRoadCenter->GetActorLocation();
    location.X += 1000;
    OtherActor->SetActorLocation(location);
    LastRoadCenter = OtherActor;
}

