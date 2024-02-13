
#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	PlayerTank = PlayerPawn ? Cast<ATank>(PlayerPawn) : nullptr;
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerTank)
	{
		MoveToActor(PlayerTank, AcceptanceRadius);
		
		ATank* TankAI = Cast<ATank>(GetPawn());
		TankAI->AimAt(PlayerTank->GetActorLocation());
		TankAI->Fire();
	}
}
