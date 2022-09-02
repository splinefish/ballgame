#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "LabyrinthLevel.generated.h"

UCLASS()
class LABYRINTH_API ALabyrinthLevel : public APawn
{
	GENERATED_BODY()

public:
	ALabyrinthLevel();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
    APlayerController* PlayerController;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
    float MaxTilt = 10.0f;

	UPROPERTY(EditAnywhere)
    float RotationSpeed = 2.0f;
};
