// Fill out your copyright notice in the Description page of Project Settings.


#include "RoadBase.h"

// Sets default values
ARoadBase::ARoadBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	{
		//CreateDefaultSubobject무조건 생성자 함수에서만 사용 가능.
		uSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefualtSceneRoot"));

		RootComponent = uSceneComponent;//RootComponent이미 기본적으로 생성되어있음 (from Actor.h)
		//DefaultSceneRoot만듦.
	}

	{
	//CreateDefaultSubobject무조건 생성자 함수에서만 사용 가능.
	uStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	//uStaticMeshComponent->SetupAttachment(RootComponent); //(자식구조)

	RootComponent = uStaticMeshComponent;	//바로 root에 넣기
	}

	//자동 방법
	auto MyStaticMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Meshes/MyStaticMesh.MyStaticMesh'"));
	//수동 방법
	/*FString path = "StaticMesh'/Game/Meshes/MyStaticMesh.MyStaticMesh'";
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MyStaticMesh
	(
		TEXT("StaticMesh'/Game/Meshes/MyStaticMesh.MyStaticMesh'")
	);*/

	if (MyStaticMesh.Succeeded()) {	//component에 mystaticmesh 연결시키고, 스케일 지정
		uStaticMeshComponent->SetStaticMesh(MyStaticMesh.Object); //MyStaticMesh는 포인터이므로
		uStaticMeshComponent->SetRelativeScale3D(FVector(10, 10, 1));
	}

	//머터리얼 초기화는 여기 생성자에서 하면 안됨. 오브젝트 월드에 인스턴스 후에 해야하므로 . 상속 받는 곳에서
	//상속 받는 곳 : Road Center Road Left Road Right 이런 곳에서.

	//컴포넌트 등록
	{
		uMoveComponent = CreateDefaultSubobject<UMoveComponent>(TEXT("MoveComponent"));
		if (uMoveComponent != nullptr) {

			uMoveComponent->RegisterComponent();

			UE_LOG(LogTemp, Warning, TEXT("Component register complete"));
		}
	}

}

// Called when the game starts or when spawned
void ARoadBase::BeginPlay()
{
	Super::BeginPlay();
	if (uMoveComponent != nullptr) {

		uMoveComponent->Init();
	}
}

// Called every frame
void ARoadBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

