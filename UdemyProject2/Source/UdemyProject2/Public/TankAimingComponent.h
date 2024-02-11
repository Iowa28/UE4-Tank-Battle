// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UDEMYPROJECT2_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTankAimingComponent();

protected:
	virtual void BeginPlay() override;

public:	
	void AimAt(FVector HitLocation, float LaunchSpeed);

	void SetBarrel(UTankBarrel* BarrelToSet);

	void SetTurret(UTankTurret* TurretToSet);

private:
	UTankBarrel* Barrel = nullptr;
	
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
