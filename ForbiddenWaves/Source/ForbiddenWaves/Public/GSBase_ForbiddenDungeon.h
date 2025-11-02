// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "GSBase_ForbiddenDungeon.generated.h"

/**
 * 
 */
UCLASS()
class FORBIDDENWAVES_API AGSBase_ForbiddenDungeon : public AGameStateBase
{
	GENERATED_BODY()
	
public: 
	AGSBase_ForbiddenDungeon();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Waves")
	int32 CurrentWave;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Waves")
	int32 EnemiesRemaining;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Waves")
	bool bIsWaveActive;

public:
	// Getters
	UFUNCTION(BlueprintCallable, Category = "Waves")
	int32 GetCurrentWave() const { return CurrentWave; }

	UFUNCTION(BlueprintCallable, Category = "Waves")
	int32 GetEnemiesRemaining() const { return EnemiesRemaining; }

	UFUNCTION(BlueprintCallable, Category = "Waves")
	bool IsWaveActive() const { return bIsWaveActive; }

	// Setters
	void SetCurrentWave(int32 NewWave);
	void SetEnemiesRemaining(int32 NewCount);
	void SetWaveActive(bool bActive);
};
