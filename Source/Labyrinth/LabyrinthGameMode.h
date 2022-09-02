#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Ball.h"
#include "Collectable.h"
#include "LabyrinthGameMode.generated.h"

UCLASS()
class LABYRINTH_API ALabyrinthGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ALabyrinthGameMode();

	virtual void StartPlay() override;

	void Collect(AActor* actor);
	void LooseLife();
	void SpawnBall();

    void Tick( float DeltaTime ) override;

	UFUNCTION(BlueprintPure)
    int GetLives();

	UFUNCTION(BlueprintPure)
    int GetCollectableCount();

	UFUNCTION(BlueprintPure)
    FString GetTime();

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABall> Ball;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ACollectable> LevelCollectable;

	UPROPERTY(EditAnywhere)
    float DropPeneltyInSeconds = 30.0f;

private:
	FVector spawn_position;
	int collectable_count;
	int lives;
	float time;
};
