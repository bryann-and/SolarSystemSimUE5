// Fill out your copyright notice in the Description page of Project Settings.

#include "Planet.h"

// Sets default values
APlanet::APlanet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlanet::BeginPlay()
{	
	CurrentVelocity = StatingVelocity;
	MassKg = UHelpersLibrary::ConvertScientificToNumber(MassKgInScientificNotation);

	Super::BeginPlay();	
}

// Called every frame
void APlanet::Tick(float DeltaTime)
{
	/*TArray<APlanet*> array;
	array.Init(this,1);*/

	UpdateVelocity(PlanetsToConsider, DeltaTime);
	Super::Tick(DeltaTime);

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("Mass: %f"), MassKg));
}

void APlanet::UpdateVelocity(TArray<APlanet*> planetsToConsider, float deltaTime)
{
	
	FVector currentLocation = this->GetActorLocation();

	for (auto &planet : planetsToConsider)
	{		
		/*
		* F= g*(m1*m2 / d^2)
		*/
		float distanceSqrt = (planet->GetActorLocation() - currentLocation).SquaredLength();
		FVector direction = (planet->GetActorLocation() - currentLocation);
		direction.Normalize();
		FVector force = direction * gravity * (this->MassKg * planet->MassKg / distanceSqrt);

		FVector acceleration = force / this->MassKg;
		CurrentVelocity += acceleration * deltaTime;
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, CurrentVelocity.ToString());
	}
	
	this->SetActorLocation(currentLocation + CurrentVelocity);
}

