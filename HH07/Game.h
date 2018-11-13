#pragma once

#include <iostream>
#include <SDL_image.h>
#include "SDL.h"
#include "TextureManager.h"
#include "SDLGameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Ball.h"
#include "Wall.h"
#include "InputHandler.h"
#include <vector>



class Game
{
public:
	~Game() {}

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit();
	void createGameObject_ball(Ball* ball);		// 공 생성 함수
	bool running() { return m_bRunning; }

	static Game* Instance();

	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	std::vector<SDLGameObject*> m_gameObjects;
	vector<Ball*> Balls;	// 공만 따로 충돌체크하기 위해서 담아두기 위한 vector

private:
	Game() {};

	// create the s_pInstance member variable
	static Game* s_pInstance;

	

	SDL_Window * m_pWindow;

	SDL_Renderer* m_pRenderer;

	

	TextureManager* m_textureManager;

	bool m_bRunning;
};

// create the typedef
typedef Game TheGame;