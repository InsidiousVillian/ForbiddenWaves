// Copyright Epic Games, Inc. All Rights Reserved.


#include "ForbiddenWavesPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "ForbiddenWavesCameraManager.h"

AForbiddenWavesPlayerController::AForbiddenWavesPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = AForbiddenWavesCameraManager::StaticClass();
}

void AForbiddenWavesPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
