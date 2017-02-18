// Fill out your copyright notice in the Description page of Project Settings.

#include "MegaGame.h"
#include "MegaGameGameModeBase.h"

#include "Floor.h"
#include "MyPlayer.h"

AMegaGameGameModeBase::AMegaGameGameModeBase()
{
    PrimaryActorTick.bCanEverTick = true;

    // Set properties
    DeathZCoord = -20.0f;
}

// Called when the game starts or when spawned
void AMegaGameGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    
    // Set PlayState to Playing By Default
    SetPlayState(EPlayState::EPlaying);
    
    // Update HUD time
    LevelTime = 10.0f;

    BeginTime = FPlatformTime::Seconds();
    UE_LOG(LogClass, Warning, TEXT(">>>>> MyTime is %f"), BeginTime);
    
    EndTime = BeginTime + LevelTime;
    UE_LOG(LogClass, Warning, TEXT(">>>>> MyTime is %f"), EndTime);
    
    HUDUpdateLevelTime();
    
    // Get Floor Actor
    TArray<AActor*> FoundFloorActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFloor::StaticClass(), FoundFloorActors);
    
    for(AActor* Actor : FoundFloorActors)
    {
        FloorActor = Cast<AFloor>(Actor);
        if (FloorActor != nullptr)
        {
            UE_LOG(LogClass, Warning, TEXT(">>>>> Point to AFloat is 0x%x"), FloorActor);
            break;
        }
    }
    
    // Get Current player
    MyPlayer = Cast<AMyPlayer>(UGameplayStatics::GetPlayerPawn(this, 0));
    UE_LOG(LogClass, Warning, TEXT(">>>>> Point to AMyPlayer is 0x%x"), MyPlayer);
}

void AMegaGameGameModeBase::ResetLevel()
{
    // Set PlayState to Playing By Default
    SetPlayState(EPlayState::EPlaying);
    
    if (MyPlayer)
    {
        MyPlayer->SetActorLocation(MyPlayer->InitLocation, false);
        MyPlayer->UpdateLifes(MyPlayer->GetLifes() - 1);
    }
}

void AMegaGameGameModeBase::ResetTimer()
{
    // Update HUD time
    LevelTime = 10.0f;
    BeginTime = FPlatformTime::Seconds();
    
    EndTime = BeginTime + LevelTime;
}

void AMegaGameGameModeBase::Tick(float DeltaSeconds)
{
    // Update HUD time
    double CurrentTime = FPlatformTime::Seconds();
    LevelTime = EndTime - CurrentTime;
    
    if (CurrentTime > EndTime)
    {
        SetPlayState(EPlayState::ETimeEnd);
    }
    
    // Get MyPlayer coordinates
    if (MyPlayer)
    {
        // Get the current location
        FVector MyPlayerLocation = MyPlayer->GetActorLocation();
        if (MyPlayerLocation.Z < DeathZCoord)
        {
            SetPlayState(EPlayState::EFell);
        }
    }
    
    HUDUpdateLevelTime();
}

void AMegaGameGameModeBase::SetPlayState(EPlayState NewState)
{
    PlayState = NewState;
    HandleNewState(PlayState);
}

void AMegaGameGameModeBase::HandleNewState(EPlayState NewState)
{
    switch(NewState)
    {
        case EPlayState::EPlaying:
        {
            // Nothing now
        }
        break;
            
        case EPlayState::EPassed:
        {
            GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Level Passed");
        }
        break;
            
        case EPlayState::ETimeEnd:
        {
            GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Time end, player has been die");
            ResetTimer();
            ResetLevel();

        }
        break;
            
        case EPlayState::EFell:
        {
            GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Player die");
            
            // Reset Game State
            ResetTimer();
            ResetLevel();

        }
        break;
            
        case EPlayState::EWon:
        {
            // Nothing now
        }
        break;
            
        case EPlayState::ELose:
        {
            // Nothing now
        }
        break;
            
        default: break;
    }
}
