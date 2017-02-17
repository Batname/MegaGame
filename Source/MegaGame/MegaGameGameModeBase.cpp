// Fill out your copyright notice in the Description page of Project Settings.

#include "MegaGame.h"
#include "MegaGameGameModeBase.h"

#include "Floor.h"
#include "MyPlayer.h"

AMegaGameGameModeBase::AMegaGameGameModeBase()
{
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMegaGameGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    
    // Update HUD time
    LevelTime = StartTime = 10.0f;
    HUDUpdateLevelTime();
    
    // Get Floar Actor
    TArray<AActor*> FoundFloarActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFloor::StaticClass(), FoundFloarActors);
    
    for(AActor* Actor : FoundFloarActors)
    {
        FloarActor = Cast<AFloor>(Actor);
        if (FloarActor != nullptr)
        {
            UE_LOG(LogClass, Warning, TEXT(">>>>> Point to AFloat is 0x%x"), FloarActor);
            break;
        }
    }
    
    // Get Current player
    MyPlayer = Cast<AMyPlayer>(UGameplayStatics::GetPlayerPawn(this, 0));
    UE_LOG(LogClass, Warning, TEXT(">>>>> Point to AMyPlayer is 0x%x"), MyPlayer);
}

void AMegaGameGameModeBase::Tick(float DeltaSeconds)
{
    // Update HUD time
    float CurrentTimeInSeconds = UGameplayStatics::GetRealTimeSeconds(GetWorld());
    LevelTime = StartTime - CurrentTimeInSeconds;
    HUDUpdateLevelTime();
}
