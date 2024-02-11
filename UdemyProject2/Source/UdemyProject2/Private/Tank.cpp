// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"

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
	Barrel = BarrelToSet;
}

void ATank::SetTurret(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurret(TurretToSet);
}

void ATank::Fire()
{
	if (!Barrel)
	{
		return;
	}

	FVector Location = Barrel->GetSocketLocation(TEXT("Projectile"));
	FRotator Rotation = Barrel->GetSocketRotation(TEXT("Projectile"));

	GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Location, Rotation);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
