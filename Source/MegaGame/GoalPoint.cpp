// Fill out your copyright notice in the Description page of Project Settings.

#include "MegaGame.h"
#include "GoalPoint.h"


// Sets default values
AGoalPoint::AGoalPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGoalPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGoalPoint::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

