// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "AttributeSet/DPlayerAttributeSet.h"
#include "GameFramework/PlayerState.h"
#include "DPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class DEMO_API ADPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ADPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

private:
	UPROPERTY(VisibleAnywhere, category = "Abilities")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, category = "Abilities")
	TObjectPtr<UDPlayerAttributeSet> PlayerAttributeSet;
};
