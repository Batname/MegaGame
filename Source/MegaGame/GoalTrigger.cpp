// Fill out your copyright notice in the Description page of Project Settings.

#include "MegaGame.h"
#include "GoalTrigger.h"


// Sets default values
AGoalTrigger::AGoalTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
    
    Box->bGenerateOverlapEvents = true;
    Box->SetRelativeScale3D(FVector(2, 2, 5));
    
    RootComponent = Box;
    Box->OnComponentBeginOverlap.AddDynamic(this, &AGoalTrigger::TriggerEnter);
    Box->OnComponentEndOverlap.AddDynamic(this, &AGoalTrigger::TriggerExit);
}

// Called when the game starts or when spawned
void AGoalTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGoalTrigger::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AGoalTrigger::Debug(FString Msg)
{
    GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Msg);
}

void AGoalTrigger::TriggerEnter(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
    Debug("Trigger Enter");
}

void AGoalTrigger::TriggerExit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    Debug("Trigger Exit");
}
