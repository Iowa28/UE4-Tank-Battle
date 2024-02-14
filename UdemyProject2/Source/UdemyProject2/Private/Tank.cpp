
#include "Tank.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();

	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent))
	{
		return;
	}
	
	TankAimingComponent->AimAt(HitLocation, TossSpeed);
}

void ATank::Fire()
{
	if (!ensure(Barrel))
	{
		return;
	}
	
	bool IsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	
	if (IsReloaded)
	{
		FVector Location = Barrel->GetSocketLocation(TEXT("Projectile"));
		FRotator Rotation = Barrel->GetSocketRotation(TEXT("Projectile"));
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Location, Rotation);
		Projectile->LaunchProjectile(LaunchSpeed);

		LastFireTime = FPlatformTime::Seconds();
	}
}

void ATank::SetBarrel(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}
