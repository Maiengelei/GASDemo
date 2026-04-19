#pragma once

#include "CoreMinimal.h"
#include "DBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "DPlayerCharacter.generated.h"

UCLASS()
class DEMO_API ADPlayerCharacter : public ADBaseCharacter
{
	GENERATED_BODY()

public:
	ADPlayerCharacter();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void PossessedBy(AController* TController) override;

private:
	UPROPERTY(VisibleAnywhere, Category="Camera")
	TObjectPtr<USpringArmComponent> CameraSpringArmComponent;

	UPROPERTY(VisibleAnywhere, Category="Camera")
	TObjectPtr<UCameraComponent> FollowCamera;
};
