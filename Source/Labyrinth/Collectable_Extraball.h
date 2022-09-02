#pragma once

#include "CoreMinimal.h"
#include "Collectable.h"
#include "Collectable_Extraball.generated.h"

UCLASS()
class LABYRINTH_API ACollectable_Extraball : public ACollectable
{
	GENERATED_BODY()
	
protected:
	void OnCollect() override;
};
