// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSet/DPlayerAttributeSet.h"

#include "GameplayEffectExtension.h"

UDPlayerAttributeSet::UDPlayerAttributeSet()
{
}

/// 修改值确认
void UDPlayerAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
	else if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
	}
}

/// 最终值确认
void UDPlayerAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
	}

	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.0f, GetMaxMana()));
	}

	if (Data.EvaluatedData.Attribute == GetDamageAttribute())
	{
		float IncomingDamage = GetDamage();
		SetDamage(0.f);
		
		// 基础减法公式
		if (IncomingDamage >0.f)
		{
			const float CurrentDefense = GetDefense();
			float FinalDamage = FMath::Max(IncomingDamage - CurrentDefense, 0.0f);
		}
	}
}
