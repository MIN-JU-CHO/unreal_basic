// Fill out your copyright notice in the Description page of Project Settings.


#include "RoadCenter.h"

void ARoadCenter::OnConstruction(const FTransform& transform)
{
}

ARoadCenter::ARoadCenter() {
	static ConstructorHelpers::FObjectFinder<UMaterial> MyMaterial
	(
		TEXT("Material'/Game/Meshes/Black.Black'")
	); 
	if (MyMaterial.Succeeded()) {
		Black = MyMaterial.Object;
	}

	
		uCube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
		uCube->SetupAttachment(RootComponent);
		static ConstructorHelpers::FObjectFinder<UStaticMesh> MyCube
		(
			TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")
		);
		if (MyCube.Succeeded()) {
			uCube->SetStaticMesh(MyCube.Object);
			uCube->SetRelativeScale3D(FVector(0.5f,0.5f, 0.5f));
			uCube->SetRelativeLocation(FVector(0.0f, -45.0f, 50.0f));

		}

		static ConstructorHelpers::FObjectFinder<UMaterial> MyBlue
		(
			TEXT("Material'/Game/Meshes/Blue.Blue'")
		);
		if (MyBlue.Succeeded()) {
			Blue = MyBlue.Object;
		}
		if (Blue != nullptr) {

			uCube->SetMaterial(0, Blue);
		}
		uStaticMeshComponent->SetMaterial(0, Black);
	//
}


void ARoadCenter::BeginPlay() {
	Super::BeginPlay();
	
}