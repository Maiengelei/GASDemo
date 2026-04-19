// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DPlayerState.h"

#include "AbilitySystemComponent.h"

ADPlayerState::ADPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	
	PlayerAttributeSet = CreateDefaultSubobject<UDPlayerAttributeSet>("PlayerAttributeSet");
}

UAbilitySystemComponent* ADPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
