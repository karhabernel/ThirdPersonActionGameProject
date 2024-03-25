#include "Actions/CAttachment.h"
#include "GameFramework/Character.h"
#include "Components/ShapeComponent.h"

#include "Global.h"

ACAttachment::ACAttachment()
{

}

void ACAttachment::BeginPlay()
{
	OwnerCharacter = Cast<ACharacter>(GetOwner());

	GetComponents<UShapeComponent>(Collisions);
	for (UShapeComponent* collision : Collisions)
	{
		if (!!collision)
		{
			collision->OnComponentBeginOverlap.AddDynamic(this, &ACAttachment::OnComponentBeginOverlap);
			collision->OnComponentEndOverlap.AddDynamic(this, &ACAttachment::OnComponentEndOverlap);
		}
	}

	OffCollision();


	Super::BeginPlay();
}

void ACAttachment::AttachTo(FName InSocketName)
{
	CheckNull(OwnerCharacter);

	AttachToComponent
	(
		OwnerCharacter->GetMesh(),
		FAttachmentTransformRules(EAttachmentRule::KeepRelative, true),
		InSocketName
	);
}

void ACAttachment::AttachToScene(class USceneComponent* InComponent, FName InSocketName)
{
		CheckNull(OwnerCharacter);

		InComponent->AttachToComponent
		(
			OwnerCharacter->GetMesh(),
			FAttachmentTransformRules(EAttachmentRule::KeepRelative, true),
			InSocketName
		);
}

void ACAttachment::OnCollision()
{
	for (UShapeComponent* collisions : Collisions)
		collisions->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void ACAttachment::OffCollision()
{
	for (UShapeComponent* collisions : Collisions)
		collisions->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ACAttachment::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CheckTrue(OtherActor == OwnerCharacter);
	CheckTrue(OwnerCharacter->GetClass() == OtherActor->GetClass());

	if (OnAttachmentBeginOverlap.IsBound())
	{
		ACharacter* otherCharacter = Cast<ACharacter>(OtherActor);

		if (!!otherCharacter)
			OnAttachmentBeginOverlap.Broadcast(OverlappedComponent, OwnerCharacter, this, otherCharacter);
	}
}

void ACAttachment::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OnAttachmentEndOverlap.IsBound())
	{
		ACharacter* otherCharacter = Cast<ACharacter>(OtherActor);

		if (!!otherCharacter)
			OnAttachmentEndOverlap.Broadcast(OverlappedComponent, OwnerCharacter, this, otherCharacter);
	}
}


