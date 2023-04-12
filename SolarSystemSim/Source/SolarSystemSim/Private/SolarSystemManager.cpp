// Fill out your copyright notice in the Description page of Project Settings.


#include "SolarSystemManager.h"

// Sets default values
ASolarSystemManager::ASolarSystemManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASolarSystemManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASolarSystemManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASolarSystemManager::UpdateVelocity(TArray<APlanet*> planetsToConsider, float deltaTime)
{
	//for (auto& planet : planetsToConsider)
	//{
	//	/*
	//	* F= g*(m1*m2 / d^2)
	//	*/
	//	float distanceSqr = (planet->GetActorLocation() - this->GetActorLocation()).SquaredLength();
	//	FVector direction = (planet->GetActorLocation() - this->GetActorLocation());
	//	direction.Normalize();
	//	FVector force = direction * gravity * (this->MassKg * planet->MassKg / distanceSqr);

	//	FVector acceleration = force / this->MassKg;
	//	CurrentVelocity += acceleration * deltaTime;
	//	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, CurrentVelocity.ToString());
	//}

	//this->SetActorLocation(this->GetActorLocation() + CurrentVelocity);
}

