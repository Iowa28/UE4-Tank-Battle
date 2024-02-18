
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

UCLASS()
class UDEMYPROJECT2_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	// How close can the AI tank get
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 1000;
	
	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn* InPawn) override;

private:
	UTankAimingComponent* AimingComponent = nullptr;
	
	UFUNCTION()
	void OnPossessedTankDeath();
};
