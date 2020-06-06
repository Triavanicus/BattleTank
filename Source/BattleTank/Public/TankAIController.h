// Copyright Colton Ward (Triavanicus). 2020. All Rights Reserved.

#pragma once

#include "Tank.h"

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;
};
