#include "Characters/DPlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/DPlayerState.h"


// Sets default values
ADPlayerCharacter::ADPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	// 角色旋转控制
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// 基础移动参数
	GetCharacterMovement()->bOrientRotationToMovement = true;            // 自动朝向移动方向
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // 旋转速率
	GetCharacterMovement()->JumpZVelocity = 600.0f;                      // 跳跃初速度
	GetCharacterMovement()->AirControl = 0.35f;                          // 空中控制能力
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;                       // 步行最快速度
	GetCharacterMovement()->MinAnalogWalkSpeed = 100.0f;                 // 控制器最小起步速度
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;         // 地面摩擦减速
	GetCharacterMovement()->BrakingDecelerationFalling = 2000.f;         // 空中阻力

	CameraSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraSpringArmComponent->SetupAttachment(GetRootComponent());
	CameraSpringArmComponent->TargetArmLength = 600.0f;
	CameraSpringArmComponent->bUsePawnControlRotation = true; // 使玩家控制旋转

	// 创建并挂载相机
	FollowCamera = CreateDefaultSubobject<UCameraComponent>("FollowCamera");
	FollowCamera->SetupAttachment(CameraSpringArmComponent, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}

UAbilitySystemComponent* ADPlayerCharacter::GetAbilitySystemComponent() const
{
	ADPlayerState* PS = Cast<ADPlayerState>(GetPlayerState());
	if (!IsValid(PS)) return nullptr;

	return PS->GetAbilitySystemComponent();
}

void ADPlayerCharacter::PossessedBy(AController* TController)
{
	Super::PossessedBy(TController);

	if (!IsValid(GetAbilitySystemComponent()) || !HasAuthority()) return;

	// 分配 OwnerActor 和 AvatarActor
	GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(), this);
	GiveStartupAbilities();
}
