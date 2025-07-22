#include <cctype>
#include <iostream>
#include <string>
#include <thread>

#include "include/termcolor.hpp"

#include "SCSRPG_Constants.h"
#include "SCSRPG_Game.h"
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
			// =================== //

			// GAME LOGO
			cout << termcolor::yellow;
			cout << Texts::GAME_TITLE_BANNER;
			cout << termcolor::reset;
			cout << Constants::NEW_LINE;

			// GAME LABEL
			cout << termcolor::on_white << termcolor::grey;
			cout << Texts::GAME_LABEL << Constants::NEW_LINE;
			cout << termcolor::reset;
			cout << Constants::NEW_LINE;

			// =================== //

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

			Terminal::Sleep(2000);
			Terminal::WaitForUserInput();

			ShowScene(S_MAIN_MENU);
		}

		static void ShowMainMenuScene(void)
		{
			PrintGameLogo();

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
			// SKIP?
			uint8_t skipFlag = 0;

			Terminal::Clear();
			Terminal::Type("Would you like to skip the introductory text? [y/n]: ", 16);
			
			cin >> skipFlag;

			switch (tolower(skipFlag))
			{
			case 'y':
				ShowScene(S_CAMP);
				break;

			case 'n':
				Terminal::Clear();
				break;

			default:
				ShowScene(S_CAMP);
				break;
			}

			// ==================== //

			cout << Texts::DIVIDING_LINES[2] << Constants::NEW_LINE;
			cout << termcolor::green;

			Terminal::Type(Texts::STORY_PROPHECY, Constants::DEFAULT_TYPING_SPEED_MILLISECONDS);

			cout << termcolor::reset;
			cout << Constants::NEW_LINE << Texts::DIVIDING_LINES[2] << Constants::NEW_LINE << Constants::NEW_LINE;

			Terminal::Sleep(2000);
			Terminal::WaitForUserInput();

			ShowScene(S_CAMP);
		}

		static void ShowCreditsScene(void)
		{
			cout << termcolor::yellow;

			cout << Texts::DIVIDING_LINES[2] << Constants::NEW_LINE;
			cout << Texts::GAME_CREDITS << Constants::NEW_LINE;
			cout << Texts::DIVIDING_LINES[2] << Constants::NEW_LINE << Constants::NEW_LINE;

			cout << termcolor::reset;

			Terminal::WaitForUserInput();
			ShowScene(S_MAIN_MENU);
		}

		// ============================================ //

		static void ShowCampScene(void)
		{
			cout << termcolor::reset;

			// INTRODUCTION
			if (Game::State->IsFirstTimeAtCamp)
			{
				Terminal::Type("[???]: \"...You! Wha... what is your name?\"", 32);
				cout << Constants::NEW_LINE;

				do
				{
					cout << Constants::NEW_LINE << "Enter a name (maximum 10 characters): ";

					char name[11];

					cin.getline(name, 10);

					Game::Player->Name = string(name);
				} while (Game::Player->Name.empty());

				cout << Constants::NEW_LINE;

				Terminal::Type("[???]: \"" + Game::Player->Name + "... " + Game::Player->Name + "...\"", 60);

				Terminal::Sleep(1500);
				cout << Constants::NEW_LINE;

				Terminal::Type("[???]: \"...it is good to see someone has finally arrived...\"", 28);

				Terminal::Sleep(1500);
				cout << Constants::NEW_LINE;

				Terminal::Type("[???]: \"...it is a great pleasure to meet you.\"", 32);

				Terminal::Sleep(1500);
				cout << Constants::NEW_LINE << Constants::NEW_LINE;

				Terminal::Type("- You find yourself in a camp. You are seated on a wooden log. In the center, a fire burns brightly.", 16);

				Terminal::Sleep(2500);
				cout << Constants::NEW_LINE;

				Terminal::Type("- The only sound you hear is the rustling of trees in the strong wind. It is a bit chilly here.", 16);

				Terminal::Sleep(2500);
				cout << Constants::NEW_LINE;

				Terminal::Type("- Yet you are not alone. Just beyond the fire, on another log, sits a mysterious figure staring into the flames.", 16);

				Terminal::Sleep(2500);
				cout << Constants::NEW_LINE << Constants::NEW_LINE;

				Terminal::Type("[???]: \"You may call me...\"", 50);

				Terminal::Sleep(1500);
				cout << Constants::NEW_LINE;

				Terminal::Sleep(1500);
				Terminal::Type("[David]: \"...David.\"", 40);

				Terminal::Sleep(1500);
				cout << Constants::NEW_LINE << Constants::NEW_LINE;

				Game::State->IsFirstTimeAtCamp = false;

				Terminal::WaitForUserInput();
			}

			// INITIAL INTERACTION
			{
				Terminal::Clear();

				cout << Texts::DIVIDING_LINES[3] << Constants::NEW_LINE;

				cout << termcolor::yellow;
				cout << Texts::LANDSCAPE_MINIATURE;
				cout << termcolor::reset;

				cout << Constants::NEW_LINE << Constants::NEW_LINE;

				Terminal::Type("You see..", 32);

				cout << Constants::NEW_LINE << Constants::NEW_LINE;

				Terminal::WaitForUserInput();
			}
		}

		// ============================================ //

		static void ShowBattleScene(void)
		{

		}
	}
}