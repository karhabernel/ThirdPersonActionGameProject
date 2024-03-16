#include "Components/CStateComponent.h"

UCStateComponent::UCStateComponent()
{

}


void UCStateComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UCStateComponent::SetIdleType()
{
	ChangeType(EStateType::Idle);
}

void UCStateComponent::SetEvadeType()
{
	ChangeType(EStateType::Evade);
}

void UCStateComponent::SetActionType()
{
	ChangeType(EStateType::Action);
}

void UCStateComponent::SetHittedType()
{
	ChangeType(EStateType::Hitted);
}

void UCStateComponent::SetDeadType()
{
	ChangeType(EStateType::Dead);
}

void UCStateComponent::ChangeType(EStateType InNewType)
{
	PrevType = Type;
	Type = InNewType;

	if (OnStateTypeChanged.IsBound())
		OnStateTypeChanged.Broadcast(PrevType, InNewType);
}
