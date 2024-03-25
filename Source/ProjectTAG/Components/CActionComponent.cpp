#include "Components/CActionComponent.h"
#include "GameFramework/Character.h"

#include "Global.h"
#include "Actions/CActionData.h"
#include "Actions/CActionData_Spawned.h"
#include "Actions/CEquipment.h"
#include "Actions/CAttachment.h"
#include "Actions/CDoAction.h"

UCActionComponent::UCActionComponent()
{
}


void UCActionComponent::BeginPlay()
{
	Super::BeginPlay();

	ACharacter* ownerCharacter = Cast<ACharacter>(GetOwner());
	CheckNull(ownerCharacter);

	for (int32 i = 0; i < (int32)EActionType::Max; i++)
	{
		if (!!DataAssets[i])
			DataAssets[i]->BeginPlay(ownerCharacter, &Datas[i]);
	}
}

void UCActionComponent::SetUnarmedMode()
{
	if (!!Datas[(int32)Type] && !!Datas[(int32)Type]->GetEquipment())
		Datas[(int32)Type]->GetEquipment()->Unequip();

	if (!!Datas[(int32)EActionType::Unarmed] && !!Datas[(int32)EActionType::Unarmed]->GetEquipment())
		Datas[(int32)EActionType::Unarmed]->GetEquipment()->Equip();

	ChangeType(EActionType::Unarmed);
}

void UCActionComponent::SetSwordMode()
{
	SetMode(EActionType::Sword);

}

void UCActionComponent::SetTwoHandSwordMode()
{
	SetMode(EActionType::TwoHandSword);
}

void UCActionComponent::SetPistolMode()
{
	SetMode(EActionType::Pistol);
}

void UCActionComponent::SetRifleMode()
{
	SetMode(EActionType::Rifle);
}

void UCActionComponent::OffAllCollisions()
{
	for (ACActionData_Spawned* data : Datas)
	{
		if (!!data == false)
			continue;

		if (!!data->GetAttachment() == false)
			continue;

		data->GetAttachment()->OffCollision();
	}
}

void UCActionComponent::End_Dead()
{
	for (int32 i = 0; i < (int32)EActionType::Max; i++)
	{
		if (!!Datas[i] && Datas[i]->GetAttachment())
			Datas[i]->GetAttachment()->Destroy();

		if (!!Datas[i] && Datas[i]->GetEquipment())
			Datas[i]->GetEquipment()->Destroy();

		if (!!Datas[i] && Datas[i]->GetDoAction())
			Datas[i]->GetDoAction()->Destroy();
	}
}

void UCActionComponent::AbortedByDamaged()
{

}

void UCActionComponent::SetMode(EActionType InType)
{
	if (Type == InType)
	{
		SetUnarmedMode();
		return;
	}
	else if (IsUnarmedMode() == false)
	{
		if (!!Datas[(int32)Type] && !!Datas[(int32)Type]->GetEquipment())
			Datas[(int32)Type]->GetEquipment()->Unequip();
	}

	if (!!Datas[(int32)InType] && !!Datas[(int32)InType]->GetEquipment())
		Datas[(int32)InType]->GetEquipment()->Equip();

	ChangeType(InType);
}

void UCActionComponent::ChangeType(EActionType InNewType)
{
	EActionType prev = Type;
	Type = InNewType;

	if (OnActionTypeChanged.IsBound())
		OnActionTypeChanged.Broadcast(prev, InNewType);
}

void UCActionComponent::DoAction()
{
	CheckTrue(IsUnarmedMode());

	if (!!Datas[(int32)Type] && !!Datas[(int32)Type]->GetDoAction())
	{
		Datas[(int32)Type]->GetDoAction()->DoAction();
	}
}

void UCActionComponent::DoSubAction()
{
	CheckTrue(IsUnarmedMode());

	if (!!Datas[(int32)Type] && !!Datas[(int32)Type]->GetDoAction())
	{
		//TODO subaction
		//bEnable
		//	? Datas[(int32)Type]->GetDoAction()->DoSubAction();
	}
}