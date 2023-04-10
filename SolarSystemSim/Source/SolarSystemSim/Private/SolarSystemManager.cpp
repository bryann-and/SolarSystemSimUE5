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

