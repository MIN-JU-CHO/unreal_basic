// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

AGameManager* UMyBlueprintFunctionLibrary::GetGameManagerRef(const UWorld* world)
{
	TArray<AActor*> actors; //액터베이스이므로
	TSubclassOf<AGameManager> findClass;
	findClass = AGameManager::StaticClass();

	UGameplayStatics::GetAllActorsOfClass(world, findClass, actors);
	
	if (actors.Num() > 0) {
		for (auto item : actors) {
			return Cast<AGameManager>(item);	//actors가 AActor이므로 자식클래스로 Cast필요
		}
	}
	return nullptr;
}
