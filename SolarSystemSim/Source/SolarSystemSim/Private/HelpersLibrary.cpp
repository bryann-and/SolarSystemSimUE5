// Fill out your copyright notice in the Description page of Project Settings.


#include "HelpersLibrary.h"

const double UHelpersLibrary::MassDevider = 1000000000.0;

double UHelpersLibrary::ConvertScientificToNumber(FString massKgSN)
{
	double result = FCString::Atod(*massKgSN) / MassDevider;
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("Mass: %f"), result));
	return result;
}
