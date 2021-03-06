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

		SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);

		
		if (!TheTextureManager::Instance()->load("assets/animate_Right-alpha.png",
			"animate_right", m_pRenderer))		// 오른쪽으로 이동하는 스프라이트 이미지를 추가
		{
			return false;
		}
		if (!TheTextureManager::Instance()->load("assets/animate_Left-alpha.png",
			"animate_left", m_pRenderer))		// 왼쪽으로 이동하는 스프라이트 이미지를 추가.
		{
			return false;
		}

		m_go = new GameObject();
		m_player = new Player();
		m_enemy = new Enemy();
		// 추가한 몬스터 객체
		m_monster1 = new Monster(2, 200, 100);	// 속도 2, 좌우 이동 거리 200, 프레임 변환 속도 100
		m_monster2 = new Monster(5, 400, 60);	// 속도 5, 좌우 이동 거리 400, 프레임 변환 속도 60

		m_go->load(100, 100, 128, 82, "animate_right");
		m_player->load(300, 300, 128, 82, "animate_right");
		m_enemy->load(100, 300, 128, 82, "animate_right");
		m_monster1->load(100, 200, 128, 82, "animate_right");
		m_monster2->load(100, 300, 128, 82, "animate_right");

		// 게임 오브젝트 배열에 각 게임 오브젝트를 추가
		m_gameObjects.push_back(m_go);
		m_gameObjects.push_back(m_player);
		m_gameObjects.push_back(m_enemy);
		m_gameObjects.push_back(m_monster1);
		m_gameObjects.push_back(m_monster2);

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

	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw(m_pRenderer);
	}


	/*m_go.draw(m_pRenderer);
	m_player.draw(m_pRenderer);*/


	/*TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82,
	m_pRenderer);

	TheTextureManager::Instance()->drawFrame("animate", 100, 100,
	128, 82, 1, m_currentFrame, m_pRenderer);*/


	//m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);
	//m_textureManager.drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);




	SDL_RenderPresent(m_pRenderer);	// 화면 제시하기
}

void Game::update()
{
	//m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	//m_go.update();
	//m_player.update();

	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
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