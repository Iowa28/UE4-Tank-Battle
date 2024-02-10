// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;

UCLASS()
class UDEMYPROJECT2_API ATank : public APawn
{
	GENERATED_BODY()

public:
	ATank();

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
public:
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 10000;
	
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrel(UTankBarrel* BarrelToSet);

private:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
