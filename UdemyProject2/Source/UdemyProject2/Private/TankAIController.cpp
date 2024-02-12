// Fill out your copyright notice in the Description page of Project Settings.


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
		ATank* TankAI = Cast<ATank>(GetPawn());
		TankAI->AimAt(PlayerTank->GetActorLocation());
		TankAI->Fire();
	}
}
