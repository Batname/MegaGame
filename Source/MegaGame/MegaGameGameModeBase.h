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
protected:
    
private:
    /** Init time for level */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level", meta=(AllowPrivateAccess=true))
    float LevelTime;
};
