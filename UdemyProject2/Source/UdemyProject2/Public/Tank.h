// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

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
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrel(UStaticMeshComponent* BarrelToSet);

private:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
