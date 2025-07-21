#include <chrono>
#include <iostream>
#include <thread>

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
	}
}