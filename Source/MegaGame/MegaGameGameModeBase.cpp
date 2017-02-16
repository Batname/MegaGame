// Fill out your copyright notice in the Description page of Project Settings.

#include "MegaGame.h"
#include "MegaGameGameModeBase.h"


AMegaGameGameModeBase::AMegaGameGameModeBase()
{

}

// Called when the game starts or when spawned
void AMegaGameGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    
    // Set default properties
    LevelTime = 10;
    
    HUDUpdateLevelTime();
}

void AMegaGameGameModeBase::Tick(float DeltaSeconds)
{
}
