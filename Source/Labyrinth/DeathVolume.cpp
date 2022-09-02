#include "DeathVolume.h"
#include "Kismet/GameplayStatics.h"

ADeathVolume::ADeathVolume()
	: GameMode(0)
{
	PrimaryActorTick.bCanEverTick = true;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	RootComponent = BoxCollider;

	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ADeathVolume::OnOverlapBegin);
}

void ADeathVolume::BeginPlay()
{
	Super::BeginPlay();
	
	GameMode = Cast<ALabyrinthGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

void ADeathVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADeathVolume::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (GameMode)
	{
		GameMode->LooseLife();
		OtherActor->Destroy();
	}
}
