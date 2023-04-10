// Fill out your copyright notice in the Description page of Project Settings.

#include "Planet.h"

// Sets default values
APlanet::APlanet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Aphelion = Perihelion = 0.0;
}

// Called when the game starts or when spawned
void APlanet::BeginPlay()
{	
	CurrentVelocity = StartingVelocityCheck = StartingVelocity;
	MassKg = UHelpersLibrary::ConvertScientificToNumber(MassKgInScientificNotation);

	Super::BeginPlay();	
}

// Called every frame
void APlanet::Tick(float DeltaTime)
{
	// User changed Starting Velocity in the UI
	if (StartingVelocityCheck != StartingVelocity)
	{
		StartingVelocityCheck = StartingVelocity;
		CurrentVelocity = StartingVelocity;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("Starting velocity changed on: %s"), *CurrentVelocity.ForwardVector.ToString()));
	}

	UpdateVelocity(PlanetsToConsider, DeltaTime);

	PrintOrbitInfo();

	Super::Tick(DeltaTime);

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("Mass: %f"), MassKg));
}

void APlanet::UpdateVelocity(TArray<APlanet*> planetsToConsider, float deltaTime)
{
	for (auto &planet : planetsToConsider)
	{		
		/*
		* F= g*(m1*m2 / d^2)
		*/		
		float distanceSqr = (planet->GetActorLocation() - this->GetActorLocation()).SquaredLength();
		FVector direction = (planet->GetActorLocation() - this->GetActorLocation());
		direction.Normalize();
		FVector force = direction * gravity * (this->MassKg * planet->MassKg / distanceSqr);

		FVector acceleration = force / this->MassKg;
		CurrentVelocity += acceleration * deltaTime;
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, CurrentVelocity.ToString());
		UHelpersLibrary::CalculateOrbitPoints(planet->GetActorLocation(), this->GetActorLocation(), Aphelion, Perihelion);
	}
	
	this->SetActorLocation(this->GetActorLocation() + CurrentVelocity);
}

void APlanet::PrintOrbitInfo()
{
	GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Red, FString::Printf(TEXT("%s Aphelion: %f | Perihelion: %f"), *CelestialName, Aphelion, Perihelion));
}

