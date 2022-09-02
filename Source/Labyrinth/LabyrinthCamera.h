#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "LabyrinthCamera.generated.h"

UCLASS()
class LABYRINTH_API ALabyrinthCamera : public APawn
{
	GENERATED_BODY()

public:
	ALabyrinthCamera();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	USceneComponent* SceneComponent;
};
