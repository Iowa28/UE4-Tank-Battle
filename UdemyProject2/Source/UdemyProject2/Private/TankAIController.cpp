
#include "TankAIController.h"
#include "Tank.h"
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

	if (!ensure(PlayerPawn))
	{
		return;
	}

	MoveToActor(PlayerPawn, AcceptanceRadius);
	AimingComponent->AimAt(PlayerPawn->GetActorLocation());

	if (AimingComponent->IsAimLocked())
	{
		AimingComponent->Fire();
	}
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if (!InPawn)
	{
		return;
	}

	ATank* PossessedTank = Cast<ATank>(InPawn);
	if (!ensure(PossessedTank))
	{
		return;
	}

	PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
}

void ATankAIController::OnPossessedTankDeath()
{
	if (GetPawn())
	{
		GetPawn()->DetachFromControllerPendingDestroy();
	}
}
