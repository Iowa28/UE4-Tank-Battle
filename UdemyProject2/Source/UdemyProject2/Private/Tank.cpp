
#include "Tank.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
// #include "TankMovementComponent.h"
#include "TankBarrel.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent)
	{
		return;
	}
	
	TankAimingComponent->AimAt(HitLocation, TossSpeed);
}

void ATank::Fire()
{
	bool IsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	
	if (Barrel && IsReloaded)
	{
		FVector Location = Barrel->GetSocketLocation(TEXT("Projectile"));
		FRotator Rotation = Barrel->GetSocketRotation(TEXT("Projectile"));
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Location, Rotation);
		Projectile->LaunchProjectile(LaunchSpeed);

		LastFireTime = FPlatformTime::Seconds();
	}
}
