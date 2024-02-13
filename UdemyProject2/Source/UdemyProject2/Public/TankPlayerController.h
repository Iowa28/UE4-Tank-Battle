
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

UCLASS()
class UDEMYPROJECT2_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;
public:
	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = .5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = .3333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

private:
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
