// Fill out your copyright notice in the Description page of Project Settings.

#include "MegaGame.h"
#include "Trig.h"


// Sets default values
ATrig::ATrig()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
    
    Box->bGenerateOverlapEvents = true;
    Box->SetRelativeScale3D(FVector(2, 2, 5));
    
    RootComponent = Box;
    Box->OnComponentBeginOverlap.AddDynamic(this, &ATrig::TriggerEnter);

}

// Called when the game starts or when spawned
void ATrig::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrig::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ATrig::Debug(FString Msg)
{
    GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Msg);
}

void ATrig::TriggerEnter(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
    Debug("Trigger Enter");
}

void ATrig::TriggerExit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}
