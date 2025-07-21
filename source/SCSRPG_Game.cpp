#include "SCSRPG_Game.h"
#include "SCSRPG_Scenes.h"

namespace SCSRPG
{
	namespace Game
	{
		void Initialize(void)
		{
			Scenes::ShowScene(Scenes::S_INTRO);
		}

		void Finish(void)
		{
			return;
		}
	}
}