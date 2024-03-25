#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Actions/CActionData_Spawned.h"
#include "CActionComponent.generated.h"

UENUM(BlueprintType)
enum class EActionType : uint8
{
	Unarmed, Sword, TwoHandSword, Pistol, Rifle, Max
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActionTypeChangedSignature, EActionType, InPrevType, EActionType, InNewType);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTTAG_API UCActionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCActionComponent();

protected:
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintPure)
		FORCEINLINE class ACActionData_Spawned* GetCurrentData() { return Datas[(int32)Type]; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE class UCActionData* GetCurrentDataAsset() { return DataAssets[(int32)Type]; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsUnarmedMode() { return Type == EActionType::Unarmed; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsSwordMode() { return Type == EActionType::Sword; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsTwoHandSwordMode() { return Type == EActionType::TwoHandSword; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsPistolMode() { return Type == EActionType::Pistol; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsRifleMode() { return Type == EActionType::Rifle; }
		
public:
	UFUNCTION(BlueprintCallable) void SetUnarmedMode();
	UFUNCTION(BlueprintCallable) void SetSwordMode();
	UFUNCTION(BlueprintCallable) void SetTwoHandSwordMode();
	UFUNCTION(BlueprintCallable) void SetPistolMode();
	UFUNCTION(BlueprintCallable) void SetRifleMode();

	void OffAllCollisions();
	void End_Dead();
	void AbortedByDamaged();

private:
	void SetMode(EActionType InType);
	void ChangeType(EActionType InNewType);

public:
	void DoAction();
	void DoSubAction();

public:
	UPROPERTY(BlueprintAssignable)
		FActionTypeChangedSignature OnActionTypeChanged;

private:
	UPROPERTY(EditDefaultsOnly)
		class UCActionData* DataAssets[(int32)EActionType::Max];

private:
	EActionType Type;

	UPROPERTY()
		class ACActionData_Spawned* Datas[(int32)EActionType::Max];
};
