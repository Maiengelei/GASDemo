// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Engine/DataAsset.h"
#include "AbilityDataAsset.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FAbilityData
{
	GENERATED_BODY()

	/// GA 对象
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gameplay Ability")
	TSubclassOf<UGameplayAbility> GameplayAbility;

	/// 当前 GA 对象对应的 Tag
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gameplay Ability")
	FGameplayTag gameplayTag;

	/// 当前 GA 对象对应的 Input Tag
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gameplay Ability")
	int32 InputID = -1;

	/// 是否为默认拥有技能
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gameplay Ability")
	bool bDefaultAbility = false;
};


UCLASS()
class DEMO_API UAbilityDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GA")
	TArray<FAbilityData> Abilities;
};
