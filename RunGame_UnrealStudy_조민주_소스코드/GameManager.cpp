// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"


// Sets default values
AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//CreateDefaultSubobject무조건 생성자 함수에서만 사용 가능.
	uSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefualtSceneRoot"));

	RootComponent = uSceneComponent;//RootComponent이미 기본적으로 생성되어있음 (from Actor.h)
	//DefaultSceneRoot만듦.

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(BoxCollision, TEXT("BoxCollision"));
	
	

	//BoxCollision(uBoxComponent)..
	delegateOnActorBegin.BindUFunction(this, FName("FuncActorBegin"));	//delegate
	BoxCollision->OnComponentBeginOverlap.Add(delegateOnActorBegin);
	//박스컴포넌트의 beginoverlap으로 해야함 ^^
	//아래는 actorbeginoverlap (triggerbox자체를 "actor"로 생성했을 때 쓰였던 코드)
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
	//생성자 함수가 아닌 여기서도 해야하는 이유: 에디터에서 변경하는 값 그대로 바로 적용하기 위해서
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

