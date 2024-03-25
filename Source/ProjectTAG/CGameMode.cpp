#include "CGameMode.h"

ACGameMode::ACGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerClass(TEXT("/Game/Characters/Player/BP_CPlayer"));
	if (PlayerClass.Class != NULL)
	{
		DefaultPawnClass = PlayerClass.Class;
	}
}

