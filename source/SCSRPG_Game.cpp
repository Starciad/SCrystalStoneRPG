#include "SCSRPG_Game.h"
#include "SCSRPG_Scenes.h"

namespace SCSRPG
{
	namespace Game
	{
		SCSRPG_Player* Player;
		GameState* State;

		void Initialize(void)
		{
			Player = new SCSRPG_Player();
			State = new GameState();

			Scenes::ShowScene(Scenes::S_INTRO);
		}

		void Finish(void)
		{
			delete Player;
			delete State;

			return;
		}

		void Reset(void)
		{
			if (!Player)
			{
				Player->Reset();
			}

			if (!State)
			{
				State->Reset();
			}
		}

		// ================================ //
		// GAME STATE

		GameState::GameState(void)
		{
			IsFirstTimeAtCamp = true;
		}

		GameState::~GameState(void)
		{

		}

		void GameState::Reset(void)
		{
		
		}

		// ================================ //
	}
}