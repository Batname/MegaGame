// Fill out your copyright notice in the Description page of Project Settings.

#include "MegaGame.h"
#include "MyPlayer.h"


// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    // Create player camera
    PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
    
    // Create camera boom
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    
    // Attach camera
    CameraBoom->SetupAttachment(RootComponent);
    PlayerCamera->SetupAttachment(CameraBoom);

}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlayer::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Bind input controller from settings editor
    InputComponent->BindAxis("MoveForward", this, &AMyPlayer::MoveForward);
    InputComponent->BindAxis("MoveRight", this, &AMyPlayer::MoveRight);
}

void AMyPlayer::MoveForward(float Val)
{
    FVector Forward(1, 0, 0);
    AddMovementInput(Forward, Val);
}

void AMyPlayer::MoveRight(float Val)
{
    FVector Right(0, 1, 0);
    AddMovementInput(Right, Val);
}

