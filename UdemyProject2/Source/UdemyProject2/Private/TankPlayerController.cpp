// Fill out your copyright notice in the Description page of Project Settings.


#include "UdemyProject2/Public/TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// ATank* Tank = GetControlledTank();
	// if (Tank)
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Tank: %s"), *Tank->GetName());
	// }
	// else
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Missing tank"));
	// }
}
