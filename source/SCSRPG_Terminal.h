#pragma once

#include <cstdint>

using namespace std;

namespace SCSRPG
{
	namespace Terminal
	{
		void Clear(void);
		void Type(const string value, const uint16_t milliseconds);
	}
}
