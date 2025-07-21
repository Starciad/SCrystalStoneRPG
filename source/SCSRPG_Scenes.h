#pragma once

#include <cstdint>

namespace SCSRPG
{
	namespace Scenes
	{
		enum SCENE_INDEX : uint8_t
		{
			S_NONE,
			S_INTRO,
			S_MAIN_MENU,
			S_CREDITS,
			S_STORY,
			S_CAMP,
			S_BATTLE,
		};

		SCENE_INDEX GetCurrentScene(void);
		void ShowScene(const SCENE_INDEX index);
	}
}