#include <iostream>
#include "include/termcolor.hpp"
#include "game.h"
#include "console.h"

using namespace std;
using namespace SCrystalStoneRPG;

static Game* game;

static void start(void)
{
	game = new Game();
	game->Initialize();
}

static void stop(void)
{
	delete game;
}

int main(void)
{
	cout << termcolor::reset;

	Clear();

	start();
	stop();

	return 0;
}
