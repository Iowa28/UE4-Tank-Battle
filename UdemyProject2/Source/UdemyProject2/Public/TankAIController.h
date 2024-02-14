
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
	virtual void Tick(float DeltaTime) override;

private:
	// How close can the AI tank get
	float AcceptanceRadius = 1000;
	
	UTankAimingComponent* AimingComponent = nullptr;
};
