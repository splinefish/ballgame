#include "Collectable.h"
#include "Kismet/GameplayStatics.h"
#include "LabyrinthGameMode.h"

ACollectable::ACollectable()
{
	PrimaryActorTick.bCanEverTick = true;

	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(SphereCollider);

	RootComponent = SphereCollider;

	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ACollectable::OnOverlapBegin);

	Time = FMath::FRand() * 10.0f;
}

void ACollectable::BeginPlay()
{
	Super::BeginPlay();
	
	GameMode = Cast<ALabyrinthGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

void ACollectable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Time += DeltaTime;

	const FVector offset(
		0.0f,
		0.0f,
		((FMath::Sin(Time * 4.0f)) * 1.0f)
    );

	Mesh->SetWorldLocation(Mesh->GetComponentLocation() + offset);
}

void ACollectable::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (GameMode)
	{
		OnCollect();
        Destroy();
	}
}

void ACollectable::OnCollect()
{
    GameMode->Collect(this);
}
