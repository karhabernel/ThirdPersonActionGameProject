#include "Characters/CPlayer.h"
#include "Global.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/PostProcessComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	//Create Components
	CHelpers::CreateSceneComponent(this, &SpringArm, "SpringArm", GetMesh());
	CHelpers::CreateSceneComponent(this, &Camera, "Camera", SpringArm);
	CHelpers::CreateSceneComponent(this, &PostProcess, "PostProcess", GetRootComponent());

	CHelpers::CreateActorComponent(this, &State, "State");

	//Component Settings
	SpringArm->SetRelativeLocation(FVector(0, 0, 140));
	SpringArm->SetRelativeRotation(FRotator(0, 90, 0));
	SpringArm->TargetArmLength = 300.f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->bUsePawnControlRotation = true;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->MaxWalkSpeed = 600.f; //Todo Status
	GetCharacterMovement()->RotationRate = FRotator(0, 720, 0);


}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	//Bind Delegate
	State->OnStateTypeChanged.AddDynamic(this, &ACPlayer::OnStateTypeChanged);
	
}

void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) 
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACPlayer::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACPlayer::Look);

		EnhancedInputComponent->BindAction(PlayerSkill, ETriggerEvent::Triggered, this, &ACPlayer::OnSkill);

		EnhancedInputComponent->BindAction(PlayerTargetLeft, ETriggerEvent::Triggered, this, &ACPlayer::OnTargetLeft);
		EnhancedInputComponent->BindAction(PlayerTargetRight, ETriggerEvent::Triggered, this, &ACPlayer::OnTargetRight);

		EnhancedInputComponent->BindAction(Menu, ETriggerEvent::Triggered, this, &ACPlayer::OnMenu);

		EnhancedInputComponent->BindAction(Weapon1, ETriggerEvent::Triggered, this, &ACPlayer::OnWeapon1);
		EnhancedInputComponent->BindAction(Weapon2, ETriggerEvent::Triggered, this, &ACPlayer::OnWeapon2);
		EnhancedInputComponent->BindAction(Weapon3, ETriggerEvent::Triggered, this, &ACPlayer::OnWeapon3);
	}
}

void ACPlayer::Move(const FInputActionValue& Value)
{
}

void ACPlayer::Look(const FInputActionValue& Value)
{

}

void ACPlayer::OnSkill(const FInputActionValue& Value)
{
}

void ACPlayer::OnTargetLeft(const FInputActionValue& Value)
{
}

void ACPlayer::OnTargetRight(const FInputActionValue& Value)
{
}

void ACPlayer::OnMenu(const FInputActionValue& Value)
{
}

void ACPlayer::OnWeapon1(const FInputActionValue& Value)
{
}

void ACPlayer::OnWeapon2(const FInputActionValue& Value)
{
}

void ACPlayer::OnWeapon3(const FInputActionValue& Value)
{
}

void ACPlayer::OnStateTypeChanged(EStateType InPrevType, EStateType InNewType)
{
}

