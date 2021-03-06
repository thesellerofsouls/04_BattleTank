// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "TankPlayerController.generated.h" //must be the last include

//Forward Declaration
class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;

	void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.3f;
	
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.f;

private:
	//start the tank moving the barrel so that a shot would it where intersects the world
	void AimTowardsCrosshair(); 
	
	//Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector&) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector&LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
