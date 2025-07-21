#include "SCSRPG_Constants.h"

namespace SCSRPG
{
	namespace Constants
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

		// SETTINGS
		const uint8_t DEFAULT_TYPING_SPEED_MILLISECONDS = 32;
	}
}