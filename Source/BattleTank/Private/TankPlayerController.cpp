// Copyright Colton Ward (Triavanicus). 2020. All Rights Reserved.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("TankPlayerController Begin Play"));
    
    ATank* ControlledTank = GetControlledTank();
    if(ControlledTank != nullptr)
    {
        UE_LOG(
            LogTemp,
            Warning,
            TEXT("TankPlayerController (%s) has a controlled tank (%s)"),
            *GetName(),
            *ControlledTank->GetName());
    }
    else
    {
        UE_LOG(
            LogTemp,
            Warning,
            TEXT("TankPlayerController (%s) does not have a controlled tank"),
            *GetName());
    }
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}
