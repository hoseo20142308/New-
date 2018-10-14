#include "Game.h"

Game* g_game = 0;	// our Game object

int main(int argc, char* argv[])
{
	g_game = new Game();
	g_game->init("PP06.ImageSprite", 100, 100, 640, 480, false);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	SDL_Delay(3000);
	g_game->clean();
	SDL_Delay(3000);
	return 0;
}