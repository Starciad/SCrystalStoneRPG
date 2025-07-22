#include "SCSRPG_Constants.h"
#include "SCSRPG_Texts.h"

namespace SCSRPG
{
	namespace Texts
	{
		// INFOS
		const string GAME_NAME("SCrystalStoneRPG");
		const string GAME_VERSION("1.0.0.0");
		const string GAME_AUTHOR("Starciad");
		const string GAME_YEAR("2025");
		const string GAME_LABEL("{ " + GAME_NAME + " - " + GAME_VERSION + " (C) " + GAME_AUTHOR + " - " + GAME_YEAR + " }");
		const string GAME_CREDITS(
R"(
  This project was entirely developed by me, Starciad, using the C++14 language in
  the year 2025. It is a simple game created for learning purposes, applying
  patterns and strategies to complete the project.

  If you're interested, check out more of my projects on GitHub at the following
  link:

  <https://github.com/Starciad>

  The game's source code can be found at:

  <https://github.com/Starciad/SCrystalStoneRPG>

  I hope you enjoyed SCrystalStoneRPG, despite its limitations and simplicity.
)"
		);

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
 //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\\
|| /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ ||
|| :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ||
||                                                                                        ||
||   _____ _____                _        _ _____ _                  ____________ _____    ||
||  /  ___/  __ \              | |      | /  ___| |                 | ___ \ ___ \  __ \   ||
||  \ `--.| /  \/_ __ _   _ ___| |_ __ _| \ `--.| |_ ___  _ __   ___| |_/ / |_/ / |  \/   ||
||   `--. \ |   | '__| | | / __| __/ _` | |`--. \ __/ _ \| '_ \ / _ \    /|  __/| | __    ||
||  /\__/ / \__/\ |  | |_| \__ \ || (_| | /\__/ / || (_) | | | |  __/ |\ \| |   | |_\ \   ||
||  \____/ \____/_|   \__, |___/\__\__,_|_\____/ \__\___/|_| |_|\___\_| \_\_|    \____/   ||
||                     __/ |                                                              ||
||                    |___/                                                               ||
||                                                                                        ||
|| :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ||
|| /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ ||
 \\-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
)";

		// STORY
		const string STORY_PROPHECY(
R"(
[*] "Long ago, a prophecy was spoken by wise scholars..."
[*] "...these scholars, now lost to time, warned of ages of true terror to come..."
[*] "...a dark lord would rule the world..."
[*] "...but a humble hero..."
[*] "...bearing the emblem of hope in his heart..."
[*] "...would restore order and peace, bringing prosperity back to the world..."
[*] "...and there would be... a happy... ending...?"
[*] "Will the hero succeed in this task...?"
[*] "Time is running out... soon it will be too late."
[*] "..."
)"
		);

		// DIALOGUES

		// OPTIONS

		// MINIATURES
		const string LANDSCAPE_MINIATURE = string(
R"(
 //===============================================\\
|| |  . . . . . |       | .  . .   .  .   .|      ||
||  \  . __ .  /        |  .  .  .   .   . |      ||
||   \__/  \__/          \ .  ________ .  /       ||
||      |  |      |       \__/ \    / \__/        ||
||      |[]|     -@-            |  |        |    _||
||___   |__|      |           _/____\_     -@-  / ||
||   \_/ @  \_____|__        /     @  \_____|__/ @||
||   @       @     @ \______/  @       @     @    ||
 \\==============================================//
)");
	}
}