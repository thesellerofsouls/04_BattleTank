// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/ConstructorHelpers.h"
#include "Math/UnrealMathUtility.h"
#include "Components/SceneComponent.h"
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max doward speed, and +1 is max up movement
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxDegreesPerSecond = 10.f; //sensible default

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxElevationDegrees = 40.f; //sensible default

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinElevationDegrees = 0.f; //sensible default


};
