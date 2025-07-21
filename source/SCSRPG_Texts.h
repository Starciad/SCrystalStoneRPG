#pragma once

#include <string>

using namespace std;

namespace SCSRPG
{
	namespace Texts
	{
		// CHARS
#if defined(_WIN32) || defined(_WIN64)
		extern const string NEW_LINE;
#elif defined(__APPLE__) && defined(__MACH__)
		extern const char NEW_LINE;
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
		extern const char NEW_LINE;
#else
		extern const char NEW_LINE;
#endif

		// INFOS
		extern const string GAME_NAME;
		extern const string GAME_VERSION;
		extern const string GAME_AUTHOR;
		extern const string GAME_YEAR;
		extern const string GAME_LABEL;

		// CHARACTERS
		extern const string DIVIDING_LINES[];

		// BANNERS
		extern const string GAME_TITLE_BANNER;

		// STORY
		extern const uint8_t STORY_PROPHECY_LENGTH;
		extern const string STORY_PROPHECY[];

		// DIALOGUES

		// OPTIONS

	}
}
