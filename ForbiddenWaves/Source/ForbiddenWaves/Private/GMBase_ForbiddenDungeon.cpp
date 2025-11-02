#include "GMBase_ForbiddenDungeon.h"
#include "Kismet/GameplayStatics.h"
#include "GSBase_ForbiddenDungeon.h"
#include "UObject/ConstructorHelpers.h"

AGMBase_ForbiddenDungeon::AGMBase_ForbiddenDungeon()
{
    GameStateClass = AGSBase_ForbiddenDungeon::StaticClass();

    // Set default pawn to the First Person Blueprint
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
    if (PlayerPawnBPClass.Succeeded())
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }

    // Set custom Player Controller Blueprint
    static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonPlayerController"));
    if (PlayerControllerBPClass.Succeeded())
    {
        PlayerControllerClass = PlayerControllerBPClass.Class;
    }
}

void AGMBase_ForbiddenDungeon::BeginPlay()
{
    Super::BeginPlay();

    // Start first wave after 2 seconds
    GetWorldTimerManager().SetTimer(WaveTimerHandle, this, &AGMBase_ForbiddenDungeon::StartWave, 2.0f, false);
}

void AGMBase_ForbiddenDungeon::StartWave()
{
    auto GS = GetGameState<AGSBase_ForbiddenDungeon>();
    if (!GS) return;

    GS->SetWaveActive(true);
    GS->SetEnemiesRemaining(3 + (GS->GetCurrentWave() * 2)); // Example difficulty scaling

    SpawnWaveEnemies(GS->GetCurrentWave());
}

void AGMBase_ForbiddenDungeon::SpawnWaveEnemies(int32 WaveNumber)
{
    UE_LOG(LogTemp, Warning, TEXT("Spawning wave %d"), WaveNumber);
    // TODO: Add actual enemy spawn logic later
}

void AGMBase_ForbiddenDungeon::EndWave()
{
    auto GS = GetGameState<AGSBase_ForbiddenDungeon>();
    if (!GS) return;

    GS->SetWaveActive(false);
    GS->SetCurrentWave(GS->GetCurrentWave() + 1);

    // Delay before next wave
    GetWorldTimerManager().SetTimer(WaveTimerHandle, this, &AGMBase_ForbiddenDungeon::StartWave, TimeBetweenWaves, false);
}

void AGMBase_ForbiddenDungeon::CheckWaveStatus()
{
    auto GS = GetGameState<AGSBase_ForbiddenDungeon>();
    if (!GS) return;

    if (GS->GetEnemiesRemaining() <= 0 && GS->IsWaveActive())
    {
        EndWave();
    }
}
