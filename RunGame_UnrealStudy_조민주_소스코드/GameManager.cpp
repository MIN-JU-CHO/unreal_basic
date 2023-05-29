// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"


// Sets default values
AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//CreateDefaultSubobject������ ������ �Լ������� ��� ����.
	uSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefualtSceneRoot"));

	RootComponent = uSceneComponent;//RootComponent�̹� �⺻������ �����Ǿ����� (from Actor.h)
	//DefaultSceneRoot����.

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(BoxCollision, TEXT("BoxCollision"));
	
	

	//BoxCollision(uBoxComponent)..
	delegateOnActorBegin.BindUFunction(this, FName("FuncActorBegin"));	//delegate
	BoxCollision->OnComponentBeginOverlap.Add(delegateOnActorBegin);
	//�ڽ�������Ʈ�� beginoverlap���� �ؾ��� ^^
	//�Ʒ��� actorbeginoverlap (triggerbox��ü�� "actor"�� �������� �� ������ �ڵ�)
	//OnActorBeginOverlap.Add(delegateOnActorBegin); //void Add(FScriptDelegate InDelegate)
}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	if (BoxCollision != nullptr) {

		BoxCollision->SetRelativeLocation(FVector::ZeroVector);
		BoxCollision->InitBoxExtent(FVector(100.0f, ExtendWidth, 100.0f));
	}

	UWorld* world = GetWorld();

	FActorSpawnParameters fsp;
	fsp.Owner = this;

	FVector vec = FVector::ZeroVector;
	FRotator rot = FRotator::ZeroRotator;


	if (world) {
		
		RoadControlCenterRef = world->SpawnActor<AControlRoadCenter>(AControlRoadCenter::StaticClass(), vec, rot, fsp);

	}
}

// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameManager::OnConstruction(const FTransform& transform)
{
	//������ �Լ��� �ƴ� ���⼭�� �ؾ��ϴ� ����: �����Ϳ��� �����ϴ� �� �״�� �ٷ� �����ϱ� ���ؼ�
	BoxCollision->SetBoxExtent(FVector(100.0f, ExtendWidth, 100.0f));
}

void AGameManager::MY_DEBUG(FString text)
{
	MYLOG("%s", *text);
}

void AGameManager::MY_SCREEN_DEBUG(FString text)
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, text);
	}
}

void AGameManager::FuncActorBegin(AActor* overlappedActor, AActor* otherActor)
{
	
		//UE_LOG(LogTemp, Warning, TEXT("FuncActorBegin: %s"), *UKismetSystemLibrary::GetDisplayName(otherActor));
		UE_LOG(LogTemp, Warning, TEXT("FuncActorBegin-other: %s"), *otherActor->GetName());
		UE_LOG(LogTemp, Warning, TEXT("FuncActorBegin-overlap: %s"), *overlappedActor->GetName());

		
}

