// Copyright Colton Ward (Triavanicus). 2020. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "TankPlayerController.generated.h"

class ATank;

/**
 *
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "Crosshair", meta = (ClampMin = "0", ClampMax = "1", DisplayName = "X Location"))
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Crosshair", meta = (ClampMin = "0", ClampMax = "1", DisplayName = "Y Location"))
	float CrosshairYLocation = 1 / 3.0f;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "0"))
	float LineTraceRange = 1000000;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	ATank* GetControlledTank() const;

	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookLocationAndDirection(FVector& OutLookLocation, FVector& OutLookDirection) const;
	bool GetLookVectorHitLocation(FVector LookLocation, FVector LookDirection, FVector& OutHitLocation) const;
};
