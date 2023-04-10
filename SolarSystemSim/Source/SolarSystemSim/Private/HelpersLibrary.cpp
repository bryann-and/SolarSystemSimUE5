// Fill out your copyright notice in the Description page of Project Settings.


#include "HelpersLibrary.h"

const double UHelpersLibrary::MassDevider = FCString::Atod(*FString("1.0e10"));

double UHelpersLibrary::ConvertScientificToNumber(FString massKgSN)
{
	double result = FCString::Atod(*massKgSN) / MassDevider;
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("Mass: %f"), result));
	return result;
}

void UHelpersLibrary::CalculateOrbitPoints(FVector centerPlanetPos, FVector thisPlanetPos, double& Aphelion, double& Perihelion)
{
	double distance = (centerPlanetPos - thisPlanetPos).Length();

	if (distance > Aphelion)
	{
		Aphelion = distance;
	}
	if (distance < Perihelion || Perihelion == 0.0)
	{
		Perihelion = distance;
	}
}
