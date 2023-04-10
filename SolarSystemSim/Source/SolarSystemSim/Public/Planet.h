// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HelpersLibrary.h"
#include "Planet.generated.h"

UCLASS(Blueprintable)
class SOLARSYSTEMSIM_API APlanet : public AActor
{
	GENERATED_BODY()
	
private:
	FVector CurrentVelocity;	
	/*Used for checking with 'StatingVelocity' to see if the user changed the starting velocity in the UI*/
	FVector StartingVelocityCheck;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere) // Can't show up in the editor otherwise gets reduced to 0.00...01
	double gravity = 0.00000066743;

protected:
	// Stores the mass after being converted from 'MassKgInScientificNotation'
	double MassKg;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	/*Celestial Body/Planet's name, will be used for HUD naming*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString CelestialName;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector StartingVelocity;
	/*Mass in Scientific notation, ex: 3.30200e23*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString MassKgInScientificNotation;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<APlanet*> PlanetsToConsider;

	double Aphelion;
	double Perihelion;
	

	// Sets default values for this actor's properties
	APlanet();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void UpdateVelocity(TArray<APlanet*> planetsToConsider, float deltaTime);

	void PrintOrbitInfo();
};
