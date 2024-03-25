#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CActionData_Spawned.generated.h"

//-----------------------------------------------------------------------------
// Equipment(Struct)
//-----------------------------------------------------------------------------
USTRUCT(BlueprintType)
struct FEquipmentData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		class UAnimMontage* AnimMontage;

	UPROPERTY(EditAnywhere)
		float PlayRate = 1.f;

	UPROPERTY(EditAnywhere)
		FName StartSection;

	UPROPERTY(EditAnywhere)
		bool bCanMove = true;

	UPROPERTY(EditAnywhere)
		bool bLookForward = true;
};

//-----------------------------------------------------------------------------
// DoAction(Struct)
//-----------------------------------------------------------------------------
USTRUCT(BlueprintType)
struct FDoActionData : public FEquipmentData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		float Power = 1.f;

	UPROPERTY(EditAnywhere)
		float HitStop;

	UPROPERTY(EditAnywhere)
		class UParticleSystem* Effect;

	UPROPERTY(EditAnywhere)
		FTransform EffectTransform;

	//UPROPERTY(EditAnywhere)
	//	TSubclassOf<class UCameraShake> ShakeClass;

	//UPROPERTY(EditAnywhere)
	//	TSubclassOf<class ACMagicBall> ProjectieClass;
};

//-----------------------------------------------------------------------------
// DataAsset_Spawned(Class)
//-----------------------------------------------------------------------------

UCLASS()
class PROJECTTAG_API ACActionData_Spawned : public AActor
{
	GENERATED_BODY()
	
public:
	friend class UCActionData;

public:
	FORCEINLINE class ACEquipment* GetEquipment() { return Equipment; }
	FORCEINLINE class ACAttachment* GetAttachment() { return Attachment; }
	FORCEINLINE class ACDoAction* GetDoAction() { return DoAction; }

private:
	class ACEquipment* Equipment;
	class ACAttachment* Attachment;
	class ACDoAction* DoAction;

};