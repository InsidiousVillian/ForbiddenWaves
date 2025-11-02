// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GMBase_ForbiddenDungeon.generated.h"

/**
 * 
 */
UCLASS()
class FORBIDDENWAVES_API AGMBase_ForbiddenDungeon : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AGMBase_ForbiddenDungeon();


protected: 
	virtual void BeginPlay() override;

	FTimerHandle WaveTimerHandle;

	UPROPERTY(EditDefaultsOnly, Category = "Waves");
	float TimeBetweenWaves = 5.0f;
	
	void StartWave();
	void EndWave();
	void SpawnWaveEnemies(int32 WaveNumber);

	void CheckWaveStatus();

};
