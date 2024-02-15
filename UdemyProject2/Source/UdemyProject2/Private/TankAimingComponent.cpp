
#include "TankAimingComponent.h"

#include "Projectile.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Kismet/GameplayStatics.h"

UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	LastFireTime = FPlatformTime::Seconds();
}

void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	bool IsReloading = ReloadTimeInSeconds > (FPlatformTime::Seconds() - LastFireTime);
	
	if (IsReloading)
	{
		FiringStatus = EFiringStatus::Reloading;
	}
	else if (IsBarrelMoving())
	{
		FiringStatus = EFiringStatus::Aiming;
	}
	else
	{
		FiringStatus = EFiringStatus::Locked;
	}
}

void UTankAimingComponent::Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	Turret = TurretToSet;
	Barrel = BarrelToSet;

	AimDirection = Barrel->GetForwardVector();
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!ensure(Barrel))
	{
		return;
	}

	FVector LaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(TEXT("Projectile"));
	
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		LaunchVelocity,
		StartLocation,
		HitLocation,
		TossSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (bHaveAimSolution)
	{
		AimDirection = LaunchVelocity.GetSafeNormal();
		MoveBarrelTowards();
	}
}

void UTankAimingComponent::Fire()
{
	if (FiringStatus == EFiringStatus::Reloading)
	{
		return;
	}

	if (!ensure(Barrel) || !ensure(ProjectileBlueprint))
	{
		return;
	}

	FVector Location = Barrel->GetSocketLocation(TEXT("Projectile"));
	FRotator Rotation = Barrel->GetSocketRotation(TEXT("Projectile"));
	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Location, Rotation);
	Projectile->LaunchProjectile(LaunchSpeed);

	LastFireTime = FPlatformTime::Seconds();
}

void UTankAimingComponent::SetProjectileBlueprint(TSubclassOf<AProjectile> ProjectileBlueprintToSet)
{
	ProjectileBlueprint = ProjectileBlueprintToSet;
}

void UTankAimingComponent::MoveBarrelTowards()
{
	if (!ensure(Barrel))
	{
		return;
	}
	
	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotation = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotation - BarrelRotation;
	
	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}

bool UTankAimingComponent::IsBarrelMoving()
{
	return !AimDirection.Equals(Barrel->GetForwardVector(), .01);
}

