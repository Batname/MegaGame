// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyPlayer.generated.h"

UCLASS()
class MEGAGAME_API AMyPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyPlayer();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    /** Move forward from keyboard input */
    UFUNCTION(BlueprintCallable, Category = PlayerControl)
    void MoveForward(float Val);
    
    /** Move right from keyboard input */
    UFUNCTION(BlueprintCallable, Category = PlayerControl)
    void MoveRight(float Val);
    
protected:
    
private:
    UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess=true), Category=Lifes)
    int Lifes;
	
};
