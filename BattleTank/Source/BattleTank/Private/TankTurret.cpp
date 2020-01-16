// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	
	auto Speed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto RotationChange = Speed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	

	SetRelativeRotation(FRotator(0.f, Rotation, 0.f));
}