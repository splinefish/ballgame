#include "Collectable_Extraball.h"
#include "LabyrinthGameMode.h"
	
void ACollectable_Extraball::OnCollect()
{
    GameMode->SpawnBall();
}
