#pragma once

#include <cstdint>
#include <string>

using namespace std;

namespace SCSRPG
{
	namespace Constants
	{
		// CHARS
#if defined(_WIN32) || defined(_WIN64)
		extern const string NEW_LINE;
#elif defined(__APPLE__) && defined(__MACH__)
		extern const char NEW_LINE;
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__) || defined(__MACH__)
		extern const char NEW_LINE;
#else
		extern const char NEW_LINE;
#endif

		// SETTINGS
		extern const uint8_t DEFAULT_TYPING_SPEED_MILLISECONDS;
	}
}
