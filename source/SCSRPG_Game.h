#pragma once

#include "SCSRPG_Entity.h"
#include "SCSRPG_Player.h"

using namespace SCSRPG::Player;

namespace SCSRPG
{
	namespace Game
	{
		class GameState
		{
		public:
			bool IsFirstTimeAtCamp;

			GameState(void);
			~GameState(void);

			void Reset(void);
		};

		extern SCSRPG_Player* Player;
		extern GameState* State;

		void Initialize(void);
		void Finish(void);
		void Reset(void);
	}
}