#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Collectable.generated.h"

class ALabyrinthGameMode;

UCLASS()
class LABYRINTH_API ACollectable : public AActor
{
	GENERATED_BODY()
	
public:	
	ACollectable();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void OnCollect();

private:
    UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	ALabyrinthGameMode* GameMode;

	float Time;

private:
	UPROPERTY(EditAnywhere)
	USphereComponent* SphereCollider;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;
};
