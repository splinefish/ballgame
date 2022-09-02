#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "BallSpawnPoint.generated.h"

UCLASS()
class LABYRINTH_API ABallSpawnPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	ABallSpawnPoint();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	USceneComponent* DummyComponent;
};
