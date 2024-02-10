// Fill out your copyright notice in the Description page of Project Settings.


#include "UdemyProject2/Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	// ATank* Tank = GetPlayerTank();
	// if (Tank)
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Player Tank: %s"), *Tank->GetName());
	// }
	// else
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Missing player tank"));
	// }
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank)
	{
		GetControlledTank()->AimAt(PlayerTank->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return PlayerPawn ? Cast<ATank>(PlayerPawn) : nullptr;
}
