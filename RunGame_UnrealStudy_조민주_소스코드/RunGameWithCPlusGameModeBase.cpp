// Copyright Epic Games, Inc. All Rights Reserved.


#include "RunGameWithCPlusGameModeBase.h"

#include "RunGameWithCPlus/MyPawn.h"

ARunGameWithCPlusGameModeBase::ARunGameWithCPlusGameModeBase() {
	DefaultPawnClass = AMyPawn::StaticClass(); //TSubclassOf<T>
}
