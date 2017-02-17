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
    EDead UMETA(DisplayName="Dead"),
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
protected:
    
private:
    /** Init time for level */
    UPROPERTY(BlueprintReadWrite, meta =(AllowPrivateAccess=true), Category = "Level")
    float LevelTime;
    
    /** Start time */
    UPROPERTY()
    float StartTime;
    
    UPROPERTY()
    class AFloor* FloorActor;
    
    UPROPERTY()
    class AMyPlayer* MyPlayer;
    
    /** Vector coords Z after Player will dies */
    UPROPERTY()
    float DeathZCoord;
    
    /** Reset level */
    UFUNCTION()
    void ResetLevel();
};
