#include <iostream>
#include <thread>
#include <chrono>
#include "console.h"

namespace SCrystalStoneRPG
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
		for (uint16_t i = 0, size = value.size(); i < size; i++)
		{
			cout << value[i];
			this_thread::sleep_for(chrono::milliseconds(milliseconds));
		}
	}
}