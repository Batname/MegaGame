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
    
    // Get float coordinates
    if (FloorActor)
    {
        // Get Floor Bounds
        FVector Orgin;
        FVector BoundsExtent;
        FloorActor->GetActorBounds(false, Orgin, BoundsExtent);
        FString TempString = FString::Printf(TEXT("Actor Position is %s"), *Orgin.ToCompactString());
        UE_LOG(LogClass, Warning, TEXT(">>>>> %s"), *TempString);
        
        // Get the current location
        FVector ActorLocation = FloorActor->GetActorLocation();
        TempString = FString::Printf(TEXT("Actor Location is %s"), *ActorLocation.ToCompactString());
        UE_LOG(LogClass, Warning, TEXT(">>>>> %s"), *TempString);
        
        // Get Transform
        FTransform Transform = FloorActor->GetTransform();
        TempString = FString::Printf(TEXT("Transform Scale3D is %s"), *Transform.GetScale3D().ToCompactString());
        UE_LOG(LogClass, Warning, TEXT(">>>>> %s"), *TempString);
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
