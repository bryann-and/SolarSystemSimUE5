// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitInfo.h"

// Sets default values
AOrbitInfo::AOrbitInfo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOrbitInfo::BeginPlay()
{
	Super::BeginPlay();	

	Aphelion = UHelpersLibrary::ConvertScientificToNumber(AphelionInKm);
	Perihelion = UHelpersLibrary::ConvertScientificToNumber(PerihelionInKm);
}

// Called every frame
void AOrbitInfo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// User changed Starting Velocity in the UI
	if (StartingVelocityCheck != StartingVelocity)
	{
		StartingVelocityCheck = StartingVelocity;
		CurrentVelocity = StartingVelocity;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("Starting velocity changed on: %s"), *CurrentVelocity.ForwardVector.ToString()));
	}
}

void AOrbitInfo::PrintOrbitInfo()
{
	GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Red, FString::Printf(TEXT("%s Aphelion: %s | Perihelion: %s"), *Planet->CelestialName, *AphelionInKm, *PerihelionInKm));
}

