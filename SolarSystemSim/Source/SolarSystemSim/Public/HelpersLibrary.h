// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HelpersLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SOLARSYSTEMSIM_API UHelpersLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	static const double MassDevider;

	static double ConvertScientificToNumber(FString massKgSN);
};
