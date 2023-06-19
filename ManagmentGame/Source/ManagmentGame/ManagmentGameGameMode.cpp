// Copyright Epic Games, Inc. All Rights Reserved.

#include "ManagmentGameGameMode.h"
#include "ManagmentGamePlayerController.h"
#include "ManagmentGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AManagmentGameGameMode::AManagmentGameGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AManagmentGamePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}