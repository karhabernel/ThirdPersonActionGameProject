#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Components/CStateComponent.h"
#include "CPlayer.generated.h"

UCLASS()
class PROJECTTAG_API ACPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	ACPlayer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

//----------------------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------------------
// Inputs
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		class UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		class UInputAction* PlayerSkill;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		class UInputAction* PlayerTargetLeft;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		class UInputAction* PlayerTargetRight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		class UInputAction* Menu;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		class UInputAction* Weapon1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		class UInputAction* Weapon2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		class UInputAction* Weapon3;
// Input Functions
protected:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void OnSkill(const FInputActionValue& Value);
	void OnTargetLeft(const FInputActionValue& Value);
	void OnTargetRight(const FInputActionValue& Value);
	void OnMenu(const FInputActionValue& Value);
	void OnWeapon1(const FInputActionValue& Value);
	void OnWeapon2(const FInputActionValue& Value);
	void OnWeapon3(const FInputActionValue& Value);

// Delegate
private:
	UFUNCTION()
		void OnStateTypeChanged(EStateType InPrevType, EStateType InNewType);

//----------------------------------------------------------------------------------------
// Variables
//----------------------------------------------------------------------------------------

//Scene Component
private:
	UPROPERTY(VisibleDefaultsOnly)
		class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleDefaultsOnly)
		class UCameraComponent* Camera;

	UPROPERTY(VisibleDefaultsOnly)
		class UPostProcessComponent* PostProcess;

//Actor Component
private:
	UPROPERTY(VisibleDefaultsOnly)
		class UCStateComponent* State;

private:

};
