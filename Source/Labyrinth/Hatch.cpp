#include "Hatch.h"

AHatch::AHatch()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

void AHatch::BeginPlay()
{
	Super::BeginPlay();
	
	time = 0.0f;
	flipped = false;
}

void AHatch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	time += DeltaTime;

	if (time >= FlipTime)
	{
		time = 0.0f;
		flipped = !flipped;

        if (flipped)
        {
			FRotator rotation = Mesh->GetComponentRotation();
            rotation.Roll += 90.0f;
            Mesh->SetWorldRotation(rotation);
        }
        else
        {
			FRotator rotation = Mesh->GetComponentRotation();
            rotation.Roll -= 90.0f;
            Mesh->SetWorldRotation(rotation);
        }
	}
}

