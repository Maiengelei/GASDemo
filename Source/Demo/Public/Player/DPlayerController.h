// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "GameFramework/PlayerController.h"
#include "DPlayerController.generated.h"

UCLASS()
class DEMO_API ADPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Input Mapping")
	TArray<TObjectPtr<UInputMappingContext>> InputMappingContexts;
};
