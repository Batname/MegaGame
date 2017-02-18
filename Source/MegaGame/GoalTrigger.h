// Fill out your copyright notice in the Description page of Project Settings.
// https://www.youtube.com/watch?v=dC1TteDPy60
// https://answers.unrealengine.com/questions/439961/c-oncomponentbeginoverlap-error-with-adddynamic.html

#pragma once

#include "GameFramework/Actor.h"
#include "GoalTrigger.generated.h"

UCLASS()
class MEGAGAME_API AGoalTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGoalTrigger();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:
    
    UFUNCTION()
    void Debug(FString Msg);
    
	UFUNCTION()
    void TriggerEnter(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
    
    UFUNCTION()
    void TriggerExit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UPROPERTY()
    class UBoxComponent* Box;
    
    /** Get game mode */
    UPROPERTY()
    class AMegaGameGameModeBase* MegaGameGameModeBase;
    
    /** Trigger State, by default 0,
     * increase when enter, increase when exit
     * Waiting for 2 for move to next level
     */
    UPROPERTY()
    uint8 TriggerState = 0x0;
};
