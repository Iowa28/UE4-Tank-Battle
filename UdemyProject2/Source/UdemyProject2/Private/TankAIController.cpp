
#include "TankAIController.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!ensure(AimingComponent))
	{
		return;
	}

	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (ensure(PlayerPawn))
	{
		MoveToActor(PlayerPawn, AcceptanceRadius);
		AimingComponent->AimAt(PlayerPawn->GetActorLocation());
		AimingComponent->Fire();
	}
}
