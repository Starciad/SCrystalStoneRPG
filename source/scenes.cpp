#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "include/termcolor.hpp"
#include "console.h"
#include "constants.h"
#include "scenes.h"
#include "textual_content.h"

using namespace std;

namespace SCrystalStoneRPG
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

		Clear();

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
	// UTILITIES
	static void WaitForUserInput(bool showPrompt = true)
	{
		if (showPrompt)
		{
			cout << "Press Any Key to Continue..." << endl;
		}

		cin.get();
	}

	// PRINTS
	static void PrintGameLogo(void)
	{
		cout << DIVIDING_LINES[0] << NEW_LINE;

		// =================== //
		
		// GAME LOGO
		cout << termcolor::yellow;
		cout << GAME_TITLE_BANNER;
		cout << termcolor::reset;
		cout << NEW_LINE << NEW_LINE;

		// GAME LABEL
		cout << termcolor::on_white << termcolor::grey;
		cout << GAME_LABEL << NEW_LINE;
		cout << termcolor::reset;
		cout << NEW_LINE;

		// =================== //

		cout << DIVIDING_LINES[0];

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
			cout << NEW_LINE;
		}

		this_thread::sleep_for(chrono::seconds(2));
		WaitForUserInput();

		ShowScene(S_MAIN_MENU);
	}

	static void ShowMainMenuScene(void)
	{
		PrintGameLogo();

		for (uint8_t i = 0; i < 5; i++)
		{
			cout << NEW_LINE;
		}

		cout << "[1] Start" << NEW_LINE;
		cout << "[2] Credits" << NEW_LINE;
		cout << "[3] Exit" << NEW_LINE;
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
		cout << DIVIDING_LINES[2] << NEW_LINE << NEW_LINE;
		cout << termcolor::green;

		for (uint8_t i = 0, length = sizeof(STORY_PROPHECY) / sizeof(STORY_PROPHECY[0]); i < length; i++)
		{
			Type(STORY_PROPHECY[i], DEFAULT_TYPING_SPEED_MILLISECONDS);

			this_thread::sleep_for(chrono::seconds(1));
			cout << NEW_LINE;
		}

		cout << NEW_LINE << DIVIDING_LINES[2] << NEW_LINE;
		cout << termcolor::reset;

		this_thread::sleep_for(chrono::seconds(5));

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