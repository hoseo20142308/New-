#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		m_bRunning = true;

		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

		//m_textureManager.load("Assets/animate-alpha.png", "animate", m_pRenderer);
		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png",
			"animate", m_pRenderer))
		{
			return false;
		}

		if (!TheTextureManager::Instance()->load("assets/tree.png",
			"tree", m_pRenderer))
		{
			return false;
		}

		if (!TheTextureManager::Instance()->load("assets/Bell.png",
			"bell", m_pRenderer))
		{
			return false;
		}

		//m_textureManager.load("Assets/animate-alpha.png", "animate2", m_pRenderer);

		/*SDL_Surface* pTempSurface = IMG_Load("Assets/animate-alpha.png");


		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

		SDL_FreeSurface(pTempSurface);

		m_sourceRectangle.w = 128;
		m_sourceRectangle.h = 82;

		m_destinationRectangle.x = m_sourceRectangle.x = 0;
		m_destinationRectangle.y = m_sourceRectangle.y = 0;
		m_destinationRectangle.w = m_sourceRectangle.w;
		m_destinationRectangle.h = m_sourceRectangle.h;*/


	}
	else
	{
		return false;	// sdl could not initialize
	}



	return true;
}

void Game::render()
{

	// clear the renderer to the draw color
	SDL_RenderClear(m_pRenderer);	// draw color로 render 지우기
									// 원본 사각형과 대상 사각형의 위치와 크기에 따라 화면에 다르게 나타남...
									//SDL_RenderCopy(m_pRenderer, m_pTexture,
									//	&m_sourceRectangle, &m_destinationRectangle);

	/*TheTextureManager::Instance()->drawFrame("animate", 0, 0,
		128, 82, 1, m_currentFrame1, m_pRenderer);

	TheTextureManager::Instance()->drawFrame("animate", 100, 100,
		128, 82, 1, m_currentFrame2, m_pRenderer);*/

	//TheTextureManager::Instance()->draw("tree", 100, 0, 500, 500, m_pRenderer);
	//TheTextureManager::Instance()->draw("Bell", 100, 100, 500, 500, m_pRenderer);

	TheTextureManager::Instance()->drawFrame("bell", 0, 100,
		500, 500, 1, m_currentFrame2, m_pRenderer);

	TheTextureManager::Instance()->drawFrame("tree", 100, 0,
		500, 500, 1, m_currentFrame1, m_pRenderer);

	

	//m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);
	//m_textureManager.drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);


	SDL_RenderPresent(m_pRenderer);	// 화면 제시하기
}

void Game::update()
{
	m_currentFrame1 = int(((SDL_GetTicks() / 100) % 3));
	m_currentFrame2 = int(((SDL_GetTicks() / 150) % 4));
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}