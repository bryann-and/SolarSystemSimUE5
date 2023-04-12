// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HelpersLibrary.h"
#include "Planet.h"
#include "OrbitInfo.h"
#include "SolarSystemManager.generated.h"

UCLASS()
class SOLARSYSTEMSIM_API ASolarSystemManager : public AActor
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(BlueprintReadWrite)
	APlanet* CenterBody;
	UPROPERTY(BlueprintReadWrite)
	TArray<AOrbitInfo*> Orbits;

	// Sets default values for this actor's properties
	ASolarSystemManager();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void UpdateVelocity(TArray<APlanet*> planetsToConsider, float deltaTime);
};
