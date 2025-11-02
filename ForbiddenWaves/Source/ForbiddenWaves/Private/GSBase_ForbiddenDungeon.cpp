// Fill out your copyright notice in the Description page of Project Settings.


#include "GSBase_ForbiddenDungeon.h"

AGSBase_ForbiddenDungeon::AGSBase_ForbiddenDungeon()
{
    // Initialize default values
    CurrentWave = 1;
    EnemiesRemaining = 0;
    bIsWaveActive = false;
}

void AGSBase_ForbiddenDungeon::SetCurrentWave(int32 NewWave){
    CurrentWave = NewWave;
}

void AGSBase_ForbiddenDungeon::SetEnemiesRemaining(int32 NewCount){
    EnemiesRemaining = NewCount;
}

void AGSBase_ForbiddenDungeon ::SetWaveActive(bool bActive){
    bIsWaveActive = bActive;
}
