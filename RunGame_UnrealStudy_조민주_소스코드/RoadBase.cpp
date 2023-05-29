// Fill out your copyright notice in the Description page of Project Settings.


#include "RoadBase.h"

// Sets default values
ARoadBase::ARoadBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	{
		//CreateDefaultSubobject������ ������ �Լ������� ��� ����.
		uSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefualtSceneRoot"));

		RootComponent = uSceneComponent;//RootComponent�̹� �⺻������ �����Ǿ����� (from Actor.h)
		//DefaultSceneRoot����.
	}

	{
	//CreateDefaultSubobject������ ������ �Լ������� ��� ����.
	uStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	//uStaticMeshComponent->SetupAttachment(RootComponent); //(�ڽı���)

	RootComponent = uStaticMeshComponent;	//�ٷ� root�� �ֱ�
	}

	//�ڵ� ���
	auto MyStaticMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Meshes/MyStaticMesh.MyStaticMesh'"));
	//���� ���
	/*FString path = "StaticMesh'/Game/Meshes/MyStaticMesh.MyStaticMesh'";
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MyStaticMesh
	(
		TEXT("StaticMesh'/Game/Meshes/MyStaticMesh.MyStaticMesh'")
	);*/

	if (MyStaticMesh.Succeeded()) {	//component�� mystaticmesh �����Ű��, ������ ����
		uStaticMeshComponent->SetStaticMesh(MyStaticMesh.Object); //MyStaticMesh�� �������̹Ƿ�
		uStaticMeshComponent->SetRelativeScale3D(FVector(10, 10, 1));
	}

	//���͸��� �ʱ�ȭ�� ���� �����ڿ��� �ϸ� �ȵ�. ������Ʈ ���忡 �ν��Ͻ� �Ŀ� �ؾ��ϹǷ� . ��� �޴� ������
	//��� �޴� �� : Road Center Road Left Road Right �̷� ������.

	//������Ʈ ���
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

