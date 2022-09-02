#include "LabyrinthLevel.h"
#include "Kismet/GameplayStatics.h"

ALabyrinthLevel::ALabyrinthLevel()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

void ALabyrinthLevel::BeginPlay()
{
	Super::BeginPlay();
	
    PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
}

void ALabyrinthLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerController)
	{
		float mousex = 0.0f;
		float mousey = 0.0f;
		int32 vpwidth = 0.0f;
		int32 vpheight = 0.0f;

		PlayerController->GetMousePosition(mousex, mousey);
		PlayerController->GetViewportSize(vpwidth, vpheight);

		const float tiltx = (mousex / (float)vpwidth) * 2.0f - 1.0f;
		const float tilty = (mousey / (float)vpheight) * 2.0f - 1.0f;

		const FRotator current_rotation = Mesh->GetComponentRotation();
		const FRotator target_rotation = FRotator(MaxTilt * tilty, 0.0f, MaxTilt * tiltx);
		Mesh->SetWorldRotation(FQuat(FMath::RInterpTo(current_rotation, target_rotation, DeltaTime, RotationSpeed)));
	}
}

void ALabyrinthLevel::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

