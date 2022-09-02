#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Hatch.generated.h"

UCLASS()
class LABYRINTH_API AHatch : public AActor
{
	GENERATED_BODY()
	
public:	
	AHatch();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
    float FlipTime = 3.0f;

	float time;
	bool flipped;
};
