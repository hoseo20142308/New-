#pragma once

#include <iostream>
#include <SDL_image.h>
#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"

class Game
{
public:
	Game() {}
	~Game() {}

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }


private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	//SDL_Texture* m_pTexture;			// the new SDL_Texture variable
	//SDL_Rect m_sourceRectangle;			// ���� �簢��
	//SDL_Rect m_destinationRectangle;	// ��� �簢��

	GameObject m_go;
	Player m_player;

	int m_currentFrame;
	TextureManager* m_textureManager;

	bool m_bRunning;
};