// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5_DialogueSystemGameMode.h"
#include "UE5_DialogueSystemCharacter.h"
#include "UObject/ConstructorHelpers.h"

#include "../Tutorial/MenuHUD.h"
#include "../Tutorial/MenuPlayerController.h"

AUE5_DialogueSystemGameMode::AUE5_DialogueSystemGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	PlayerControllerClass = AMenuPlayerController::StaticClass();
	HUDClass = AMenuHUD::StaticClass();
}
