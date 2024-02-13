
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringStatus : uint8
{
	Reloading,
	Aiming,
	Locked
};

class UTankBarrel;
class UTankTurret;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UDEMYPROJECT2_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTankAimingComponent();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringStatus = EFiringStatus::Aiming;
	
	virtual void BeginPlay() override;

public:	
	void AimAt(FVector HitLocation, float TossSpeed);

	void SetBarrel(UTankBarrel* BarrelToSet);

	void SetTurret(UTankTurret* TurretToSet);

private:
	UTankBarrel* Barrel = nullptr;
	
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
