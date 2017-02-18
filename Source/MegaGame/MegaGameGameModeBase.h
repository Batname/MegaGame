// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "MegaGameGameModeBase.generated.h"

// Current Game state
UENUM(BlueprintType)
enum class EPlayState
{
    EPlaying UMETA(DisplayName="Playing"),
    EPassed UMETA(DisplayName="Passed"),
    ETimeEnd UMETA(DisplayName="TimeEnd"),
    EFell UMETA(DisplayName="Fell"),
    EWon UMETA(DisplayName="Won"),
    ELose UMETA(DisplayName="Lose")
};

/**
 * 
 */
UCLASS()
class MEGAGAME_API AMegaGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	
public:
    AMegaGameGameModeBase();
    virtual void Tick(float DeltaSeconds) override;
    
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
    /** Update lifes in HUD */
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = HUD)
    void HUDUpdateLevelTime();
    
    
    /** Return teh current player state */
    UFUNCTION(BlueprintPure, Category = "Power")
    EPlayState GetPlayState() const { return PlayState; }
    
    /** Set a new player state */
    UFUNCTION()
    void SetPlayState(EPlayState NewState);

protected:
    /** Init time for level */
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category=Level)
    float LevelTime;
    
private:
    /** Start time */
    UPROPERTY()
    float StartTime;
    
    UPROPERTY()
    double BeginTime;
    
    UPROPERTY()
    double EndTime;
    
    UPROPERTY()
    class AFloor* FloorActor;
    
    UPROPERTY()
    class AMyPlayer* MyPlayer;
    
    /** Vector coords Z after Player will dies */
    UPROPERTY()
    float DeathZCoord;

    /** Keeps track ot the current state */
    EPlayState PlayState;
    
    /** Reset level */
    UFUNCTION()
    void ResetLevel();
    
    /** Reset Timer */
    UFUNCTION()
    void ResetTimer();
    
    /** Handling new State after Tick */
    UFUNCTION()
    void HandleNewState(EPlayState NewState);

};
