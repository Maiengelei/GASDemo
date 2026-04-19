// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "DBaseAttributeSet.h"
#include "DPlayerAttributeSet.generated.h"

// 生成 get set 等
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


UCLASS()
class DEMO_API UDPlayerAttributeSet : public UDBaseAttributeSet
{
	GENERATED_BODY()
	
public:
	UDPlayerAttributeSet();
	
	UPROPERTY(BlueprintReadOnly, Category="Vital")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UDPlayerAttributeSet, Health)

	UPROPERTY(BlueprintReadOnly, Category="Vital")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UDPlayerAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, Category="Resource")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UDPlayerAttributeSet, Mana)

	UPROPERTY(BlueprintReadOnly, Category="Resource")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UDPlayerAttributeSet, MaxMana)

	UPROPERTY(BlueprintReadOnly, Category="Combat")
	FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(UDPlayerAttributeSet, AttackPower)

	UPROPERTY(BlueprintReadOnly, Category="Combat")
	FGameplayAttributeData Defense;
	ATTRIBUTE_ACCESSORS(UDPlayerAttributeSet, Defense)

	UPROPERTY(BlueprintReadOnly, Category="Charge")
	FGameplayAttributeData MaxChargeTime;
	ATTRIBUTE_ACCESSORS(UDPlayerAttributeSet, MaxChargeTime)

	UPROPERTY(BlueprintReadOnly, Category="Charge")
	FGameplayAttributeData ChargeDamageMultiplier;
	ATTRIBUTE_ACCESSORS(UDPlayerAttributeSet, ChargeDamageMultiplier)
	
	UPROPERTY(BlueprintReadOnly, Category="Charge")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UDPlayerAttributeSet, Damage)
	
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
