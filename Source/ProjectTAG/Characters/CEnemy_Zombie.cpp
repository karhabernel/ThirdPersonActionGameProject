// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CEnemy_Zombie.h"

// Sets default values
ACEnemy_Zombie::ACEnemy_Zombie()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACEnemy_Zombie::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACEnemy_Zombie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACEnemy_Zombie::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

