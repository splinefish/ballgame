#include "LabyrinthGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "BallSpawnPoint.h"

ALabyrinthGameMode::ALabyrinthGameMode()
{
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;
}

void ALabyrinthGameMode::StartPlay()
{
    Super::StartPlay();

    time = 0.0f;
    lives = 3;

    // Get spawn position
    {
        ABallSpawnPoint* spawn = Cast<ABallSpawnPoint>(UGameplayStatics::GetActorOfClass(GetWorld(), ABallSpawnPoint::StaticClass()));

        if (spawn)
        {
            spawn_position = spawn->GetActorLocation();
        }
        else
        {
            // Crash game
        }
    }

    // Count level collectables
    {
        collectable_count = 0;

        TArray<AActor*> actors;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), LevelCollectable, actors);

        collectable_count = actors.Num();
    }

    SpawnBall();
}

void ALabyrinthGameMode::LooseLife()
{
    if (collectable_count)
    {
        time += DropPeneltyInSeconds;
    }

    SpawnBall();
}

void ALabyrinthGameMode::SpawnBall()
{
    ABall* new_ball = GetWorld()->SpawnActor<ABall>(Ball, spawn_position, FRotator({0.0f, 0.0f, 0.0f}));
}

void ALabyrinthGameMode::Collect(AActor* actor)
{
    if (actor->IsA(LevelCollectable))
    {
        collectable_count--;
    }
}

void ALabyrinthGameMode::Tick(float DeltaTime)
{
    if (collectable_count)
    {
        time += DeltaTime;
    }
}

int ALabyrinthGameMode::GetLives()
{
    return lives;
}

int ALabyrinthGameMode::GetCollectableCount()
{
    return collectable_count;
}

FString ALabyrinthGameMode::GetTime()
{
    float remaining = time;
    const int hours = (int)(remaining / 60.0f / 60.0f);
    remaining -= (float)(hours * 60 * 60);
    const int minutes = (int)(remaining / 60.0f);
    remaining -= (float)(minutes * 60);
    const int seconds = (int)remaining;

    return FString::Printf(TEXT("%02i:%02i:%02i"), hours, minutes, seconds);
}
