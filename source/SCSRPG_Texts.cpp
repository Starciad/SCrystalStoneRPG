#include "SCSRPG_Texts.h"

namespace SCSRPG
{
	namespace Texts
	{
		// CHARS
#if defined(_WIN32) || defined(_WIN64)
		const string NEW_LINE("\r\n");
#elif defined(__APPLE__) && defined(__MACH__)
		const char NEW_LINE = '\n';
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
		const char NEW_LINE = '\n';
#else
		const char NEW_LINE = '\n';
#endif

		// INFOS
		const string GAME_NAME("SCrystalStoneRPG");
		const string GAME_VERSION("1.0.0.0");
		const string GAME_AUTHOR("Starciad");
		const string GAME_YEAR("2025");
		const string GAME_LABEL("{ " + GAME_NAME + " - " + GAME_VERSION + " (C) " + GAME_AUTHOR + " - " + GAME_YEAR + " }");

		// CHARACTERS
		const string DIVIDING_LINES[] =
		{
			"[=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=]",
			"{+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+}",
			"{-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-}",
			"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-",
		};

		// BANNERS
		const string GAME_TITLE_BANNER =
R"(
   ______                __        _______ __                   ____  ____  ______
  / ____/______  _______/ /_____ _/ / ___// /_____  ____  ___  / __ \/ __ \/ ____/
 / /   / ___/ / / / ___/ __/ __ `/ /\__ \/ __/ __ \/ __ \/ _ \/ /_/ / /_/ / / __  
/ /___/ /  / /_/ (__  ) /_/ /_/ / /___/ / /_/ /_/ / / / /  __/ _, _/ ____/ /_/ /  
\____/_/   \__, /____/\__/\__,_/_//____/\__/\____/_/ /_/\___/_/ |_/_/    \____/   
          /____/                                                                  
)";

		// STORY
		const uint8_t STORY_PROPHECY_LENGTH = 10;
		const string STORY_PROPHECY[] =
		{
			/* 00 */ string(R"("Long ago, a prophecy was spoken by wise scholars...")"),
			/* 01 */ string(R"("...these scholars, now lost to time, warned of ages of true terror to come...")"),
			/* 02 */ string(R"("...a dark lord would rule the world...")"),
			/* 03 */ string(R"("...but a humble hero...")"),
			/* 04 */ string(R"("...bearing the emblem of hope in his heart...")"),
			/* 05 */ string(R"("...would restore order and peace, bringing prosperity back to the world...")"),
			/* 06 */ string(R"("...and there would be... a happy... ending...?")"),
			/* 07 */ string(R"("Will the hero succeed in this task...?")"),
			/* 08 */ string(R"("Time is running out... soon it will be too late.")"),
			/* 09 */ string(R"("...")"),
		};

		// DIALOGUES

		// OPTIONS

	}
}