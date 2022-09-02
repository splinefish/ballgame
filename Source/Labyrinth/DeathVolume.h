#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "LabyrinthGameMode.h"
#include "DeathVolume.generated.h"

UCLASS()
class LABYRINTH_API ADeathVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	ADeathVolume();

	virtual void Tick(float DeltaTime) override;

    UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	UBoxComponent* BoxCollider;

	ALabyrinthGameMode* GameMode;
};
