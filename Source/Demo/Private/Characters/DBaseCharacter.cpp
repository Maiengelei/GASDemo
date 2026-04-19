#include "Demo/Public/Characters/DBaseCharacter.h"

#include "AbilitySystemComponent.h"


ADBaseCharacter::ADBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	// 切换动画更新策略为实时更新
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}

UAbilitySystemComponent* ADBaseCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}

void ADBaseCharacter::GiveStartupAbilities()
{
	if (!IsValid(GetAbilitySystemComponent())) return;

	// for (const auto& Ability : StartupAbilities)
	// {
	// 	FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability);
	// 	GetAbilitySystemComponent()->GiveAbility(AbilitySpec);
	// }
	
	for (const auto& Ability: StartupAbilities->Abilities)
	{
		if (!Ability.bDefaultAbility == true) continue;
		
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability.GameplayAbility);
		AbilitySpec.InputID = Ability.InputID;
		
		GetAbilitySystemComponent()->GiveAbility(AbilitySpec);
	}
}
