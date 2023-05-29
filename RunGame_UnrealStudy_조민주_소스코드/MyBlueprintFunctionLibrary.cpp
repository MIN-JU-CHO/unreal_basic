// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

AGameManager* UMyBlueprintFunctionLibrary::GetGameManagerRef(const UWorld* world)
{
	TArray<AActor*> actors; //���ͺ��̽��̹Ƿ�
	TSubclassOf<AGameManager> findClass;
	findClass = AGameManager::StaticClass();

	UGameplayStatics::GetAllActorsOfClass(world, findClass, actors);
	
	if (actors.Num() > 0) {
		for (auto item : actors) {
			return Cast<AGameManager>(item);	//actors�� AActor�̹Ƿ� �ڽ�Ŭ������ Cast�ʿ�
		}
	}
	return nullptr;
}
