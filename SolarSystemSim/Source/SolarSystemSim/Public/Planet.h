// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Planet.generated.h"

UCLASS(Blueprintable)
class SOLARSYSTEMSIM_API APlanet : public AActor
{
	GENERATED_BODY()
	
private:
	FVector CurrentVelocity;	
	double gravity = 0.00000066743;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector StatingVelocity;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MassKg;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<APlanet*> PlanetsToConsider;

	// Sets default values for this actor's properties
	APlanet();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void UpdateVelocity(TArray<APlanet*> planetsToConsider, float deltaTime);

};
