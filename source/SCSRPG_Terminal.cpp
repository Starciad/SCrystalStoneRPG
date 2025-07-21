#include <chrono>
#include <iostream>
#include <thread>

#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

#include "SCSRPG_Terminal.h"

namespace SCSRPG
{
	namespace Terminal
	{
		void Clear(void)
		{
#ifdef _WIN32
			std::system("cls");
#else
			std::system("clear");
#endif
		}

		void Type(const string value, const uint16_t milliseconds)
		{
			for (uint16_t i = 0, size = (uint16_t)value.size(); i < size; i++)
			{
				cout << value[i];
				this_thread::sleep_for(chrono::milliseconds(milliseconds));
			}
		}

#if !defined(_WIN32) && !defined(_WIN64)
		static int getch_unix()
		{
			struct termios oldt, newt;
			tcgetattr(STDIN_FILENO, &oldt);
			newt = oldt;
			newt.c_lflag &= ~(ICANON | ECHO);
			tcsetattr(STDIN_FILENO, TCSANOW, &newt);
			int ch = getchar();
			tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
			return ch;
		}
#endif

		void WaitForUserInput(bool showPrompt)
		{
			if (showPrompt)
			{
				cout << "Press Any Key to Continue..." << endl;
			}

#if defined(_WIN32) || defined(_WIN64)
			_getch();
#else
			getch_unix();
#endif
		}
	}
}
