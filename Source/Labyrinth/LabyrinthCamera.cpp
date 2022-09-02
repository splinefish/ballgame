#include "LabyrinthCamera.h"

ALabyrinthCamera::ALabyrinthCamera()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	Camera->SetupAttachment(SceneComponent);

	RootComponent = SceneComponent;
}

void ALabyrinthCamera::BeginPlay()
{
	Super::BeginPlay();
}

void ALabyrinthCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALabyrinthCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

