// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Planet.h"
#include "OrbitInfo.generated.h"

UCLASS()
class SOLARSYSTEMSIM_API AOrbitInfo : public AActor
{
	GENERATED_BODY()
	
private:
	FVector CurrentVelocity;
	/*Used for checking with 'StatingVelocity' to see if the user changed the starting velocity in the UI*/
	FVector StartingVelocityCheck;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere) // Can't show up in the editor otherwise gets reduced to 0.00...01
	double gravity = 0.00000066743;
	
public:	
	double Aphelion;
	double Perihelion;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	APlanet* Planet;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	/*Aphelion in Km in Scientific notation, ex: 3.30200e23*/
	FString AphelionInKm;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	/*Perihelion in Km in Scientific notation, ex: 3.30200e23*/
	FString PerihelionInKm;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector StartingVelocity;

	// Sets default values for this actor's properties
	AOrbitInfo();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void PrintOrbitInfo();

};
