// Fill out your copyright notice in the Description page of Project Settings.


#include "TesterActor.h"

// Sets default values
ATesterActor::ATesterActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATesterActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Tester Actor is working"));
}

// Called every frame
void ATesterActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

