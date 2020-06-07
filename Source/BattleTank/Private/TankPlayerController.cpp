// Copyright Colton Ward (Triavanicus). 2020. All Rights Reserved.

#include "TankPlayerController.h"

#include "Tank.h"

#include "Engine/World.h"
#include "CollisionQueryParams.h"

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

void ATankPlayerController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if(!GetControlledTank())
    {
        return;
    }

    FVector HitLocation;
    if(GetSightRayHitLocation(HitLocation))
    {
        UE_LOG(
            LogTemp,
            Warning,
            TEXT("HitLocation: %s"),
            *HitLocation.ToString());
    }

    // Get world location through crosshair
    // if it hits landscape
        // tell controlled tank to aim at this point
}


bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation)
const
{
    FVector LookLocation;
    FVector LookDirection;
    if(GetLookLocationAndDirection(LookLocation, LookDirection))
    {
        return GetLookVectorHitLocation(
            LookLocation, LookDirection, OutHitLocation);
    }
    return false;
}

bool ATankPlayerController::GetLookLocationAndDirection(
    FVector& OutLookLocation, FVector& OutLookDirection) const
{
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    return DeprojectScreenPositionToWorld(
        ViewportSizeX * CrosshairXLocation,
        ViewportSizeY * CrosshairYLocation,
        OutLookLocation,
        OutLookDirection
    );
}

bool ATankPlayerController::GetLookVectorHitLocation(
    FVector LookLocation,
	FVector LookDirection,
    FVector& OutHitLocation) const
{
    FVector Start = LookLocation;
    FVector End = Start + (LookDirection * LineTraceRange);
    FHitResult HitResult;
    if (GetWorld()->LineTraceSingleByChannel(
        HitResult,
        Start,
        End,
        ECollisionChannel::ECC_WorldStatic))
    {
    OutHitLocation = HitResult.Location;
        return true;
    }
    
    return false;
}