#include <iostream>

#include "include/termcolor.hpp"

#include "SCSRPG_Game.h"
#include "SCSRPG_Terminal.h"

using namespace std;
using namespace SCSRPG;

static void Start(void)
{
	Game::Initialize();
}

static void Stop(void)
{
	Game::Finish();
}

int main(void)
{
	cout << termcolor::reset;

	Terminal::Clear();

	Start();
	Stop();

	return 0;
}
