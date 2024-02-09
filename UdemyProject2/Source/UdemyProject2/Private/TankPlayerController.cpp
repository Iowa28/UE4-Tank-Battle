// Fill out your copyright notice in the Description page of Project Settings.


#include "UdemyProject2/Public/TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
