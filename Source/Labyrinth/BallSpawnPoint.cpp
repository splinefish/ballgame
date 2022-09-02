#include "BallSpawnPoint.h"

ABallSpawnPoint::ABallSpawnPoint()
{
	PrimaryActorTick.bCanEverTick = true;

	DummyComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy"));

    RootComponent = DummyComponent;
}

void ABallSpawnPoint::BeginPlay()
{
	Super::BeginPlay();
}

void ABallSpawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

