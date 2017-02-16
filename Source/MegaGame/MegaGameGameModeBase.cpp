// Fill out your copyright notice in the Description page of Project Settings.

#include "MegaGame.h"
#include "MegaGameGameModeBase.h"


AMegaGameGameModeBase::AMegaGameGameModeBase()
{
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMegaGameGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    
    // Set default properties
    LevelTime = StartTime = 10.0f;
    
    HUDUpdateLevelTime();
}

void AMegaGameGameModeBase::Tick(float DeltaSeconds)
{
    float CurrentTimeInSeconds = UGameplayStatics::GetRealTimeSeconds(GetWorld());
    LevelTime = StartTime - CurrentTimeInSeconds;
    HUDUpdateLevelTime();
}
