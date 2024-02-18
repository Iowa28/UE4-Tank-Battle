
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/*
 * Responsible for helping the player aim
 */
UCLASS()
class UDEMYPROJECT2_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimingComponentRef);
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float CrossHairXLocation = .5;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float CrossHairYLocation = .3333;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LineTraceRange = 1000000;

	virtual void SetPawn(APawn* InPawn) override;
	
	UFUNCTION()
	void OnPlayerTankDeath();

private:
	UTankAimingComponent* AimingComponent = nullptr;
	
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
