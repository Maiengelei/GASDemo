#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbility.h"
#include "DataAssets/AbilityDataAsset.h"
#include "GameFramework/Character.h"
#include "DBaseCharacter.generated.h"

UCLASS()
class DEMO_API ADBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ADBaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	void GiveStartupAbilities();

private:
	/// 角色初始技能组
	// UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	// TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

	/// 角色初始技能组
	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	UAbilityDataAsset* StartupAbilities;
};
