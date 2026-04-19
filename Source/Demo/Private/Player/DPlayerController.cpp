// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void ADPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer());
	if (!IsValid(InputSubsystem)) return;

	/// TODO: 以后改成从 DataAsset 加载
	for (UInputMappingContext* Context : InputMappingContexts)
	{
		int32 ContextCount = 0;
		InputSubsystem->AddMappingContext(Context, ContextCount);
		ContextCount += 1;
	}
	
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
}
