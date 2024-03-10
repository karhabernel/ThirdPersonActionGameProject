#include "Characters/CPlayer.h"
#include "Global.h"

ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACPlayer::BeginPlay()
{

	Super::BeginPlay();
	
}

void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

