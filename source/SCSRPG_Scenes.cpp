#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include "include/termcolor.hpp"

#include "SCSRPG_Constants.h"
#include "SCSRPG_Scenes.h"
#include "SCSRPG_Terminal.h"
#include "SCSRPG_Texts.h"

using namespace std;

namespace SCSRPG
{
	namespace Scenes
	{
		static SCENE_INDEX currentSceneIndex;

		// SCENES
		static void ShowIntroScene(void);
		static void ShowMainMenuScene(void);
		static void ShowCreditsScene(void);
		static void ShowStoryScene(void);
		static void ShowCampScene(void);
		static void ShowBattleScene(void);

		void ShowScene(const SCENE_INDEX index)
		{
			cout << termcolor::reset;

			Terminal::Clear();

			switch (index)
			{
			case S_NONE:
				break;

			case S_INTRO:
				ShowIntroScene();
				break;

			case S_MAIN_MENU:
				ShowMainMenuScene();
				break;

			case S_CREDITS:
				ShowCreditsScene();
				break;

			case S_STORY:
				ShowStoryScene();
				break;

			case S_CAMP:
				ShowCampScene();
				break;

			case S_BATTLE:
				ShowBattleScene();
				break;

			default:
				break;
			}

			currentSceneIndex = index;
		}

		SCENE_INDEX GetCurrentScene(void)
		{
			return currentSceneIndex;
		}

		// ================================= //
		// PRINTS
		static void PrintGameLogo(void)
		{
			cout << Texts::DIVIDING_LINES[0] << Constants::NEW_LINE;

			// =================== //

			// GAME LOGO
			cout << termcolor::yellow;
			cout << Texts::GAME_TITLE_BANNER;
			cout << termcolor::reset;
			cout << Constants::NEW_LINE << Constants::NEW_LINE;

			// GAME LABEL
			cout << termcolor::on_white << termcolor::grey;
			cout << Texts::GAME_LABEL << Constants::NEW_LINE;
			cout << termcolor::reset;
			cout << Constants::NEW_LINE;

			// =================== //

			cout << Texts::DIVIDING_LINES[0];

			cout << termcolor::reset;
			cout << endl;
		}

		static void PrintInputDefaultMessage(const int min, const int max)
		{
			cout << "Enter the desired option (" << min << '-' << max << ')' << ": ";
		}

		// ================================= //
		// SCENES

		static void ShowIntroScene(void)
		{
			PrintGameLogo();

			for (uint8_t i = 0; i < 5; i++)
			{
				cout << Constants::NEW_LINE;
			}

			this_thread::sleep_for(chrono::seconds(2));
			
			Terminal::WaitForUserInput();
			ShowScene(S_MAIN_MENU);
		}

		static void ShowMainMenuScene(void)
		{
			PrintGameLogo();

			for (uint8_t i = 0; i < 5; i++)
			{
				cout << Constants::NEW_LINE;
			}

			cout << "[1] Start" << Constants::NEW_LINE;
			cout << "[2] Credits" << Constants::NEW_LINE;
			cout << "[3] Exit" << Constants::NEW_LINE;
			cout << endl;

			uint8_t option = 0;

		INVALID_INPUT_LOOP:;
			PrintInputDefaultMessage(1, 3);
			cin >> option;

			switch (option - '0')
			{
			case 1:
				ShowScene(S_STORY);
				break;

			case 2:
				ShowScene(S_CREDITS);
				break;

			case 3:
				exit(0);
				break;

			default:
				goto INVALID_INPUT_LOOP;
				break;
			}
		}

		static void ShowStoryScene(void)
		{
			cout << Texts::DIVIDING_LINES[2] << Constants::NEW_LINE << Constants::NEW_LINE;
			cout << termcolor::green;

			for (uint8_t i = 0; i < Texts::STORY_PROPHECY_LENGTH; i++)
			{
				Terminal::Type(Texts::STORY_PROPHECY[i], Constants::DEFAULT_TYPING_SPEED_MILLISECONDS);

				this_thread::sleep_for(chrono::seconds(1));
				cout << Constants::NEW_LINE;
			}

			cout << termcolor::reset;
			cout << Constants::NEW_LINE << Texts::DIVIDING_LINES[2] << Constants::NEW_LINE << Constants::NEW_LINE;

			this_thread::sleep_for(chrono::seconds(2));
			
			Terminal::WaitForUserInput();
			ShowScene(S_CAMP);
		}

		static void ShowCreditsScene(void)
		{

		}

		static void ShowCampScene(void)
		{

		}

		static void ShowBattleScene(void)
		{

		}
	}
}