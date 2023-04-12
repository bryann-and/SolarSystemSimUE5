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
	
protected:
	// Stores the mass after being converted from 'MassKgInScientificNotation'
	double MassKg;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	/*Celestial Body/Planet's name, will be used for HUD naming*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString CelestialName;	
	/*Mass in Kg in Scientific notation, ex: 3.30200e23*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString MassKgInScientificNotation;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<APlanet*> PlanetsToConsider;

	// Sets default values for this actor's properties
	APlanet();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
