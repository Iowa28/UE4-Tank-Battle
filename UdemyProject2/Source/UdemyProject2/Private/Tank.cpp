// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "TankAimingComponent.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetBarrel(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrel(BarrelToSet);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
