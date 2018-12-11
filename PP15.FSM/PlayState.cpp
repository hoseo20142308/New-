#include "PlayState.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "Game.h"

const std::string PlayState::s_playID = "PLAY";

PlayState* PlayState::s_pInstance = 0;

void PlayState::update()
{
	GameManager::Instance()->update();
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	/*if (checkCollision(
		dynamic_cast<SDLGameObject*>(m_gameObjects[0]),
		dynamic_cast<SDLGameObject*>(m_gameObjects[1])))
	{
		TheGame::Instance()->getStateMachine()->changeState(
			GameOverState::Instance());
	}*/

	pop_vector();

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->changeState(
			PauseState::Instance());
	}
	
	
}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/Sky.png",
		"background", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load(
		"assets/helicopter.png", "helicopter",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/helicopter2.png",
		"helicopter2", TheGame::Instance()->getRenderer())) 
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/bullet.png",
		"bullet", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* background = new SDLGameObject(new LoaderParams(0, 0, 816, 816, 640, 480, "background"));
	m_gameObjects.push_back(background);

	GameObject* player = new Player(new LoaderParams(100, 100, 128, 55, 50, 30, "helicopter"));
	
	m_gameObjects.push_back(player);
	list_Player.push_back(player);

	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < list_Player.size(); i++)
	{
		list_Player[i]->clean();
	}
	list_Player.clear();

	for (int i = 0; i < list_Enemy.size(); i++)
	{
		list_Enemy[i]->clean();
	}
	list_Enemy.clear();

	for (int i = 0; i < list_Bullet.size(); i++)
	{
		list_Bullet[i]->clean();
	}
	list_Bullet.clear();

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();



	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	TheTextureManager::Instance()->clearFromTextureMap("helicopter2");
	std::cout << "exiting PlayState\n";
	return true;
}

PlayState * PlayState::Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new PlayState();
		return s_pInstance;
	}
	return s_pInstance;
}

void PlayState::pop_vector()
{
	GameObject* tempO;
	// 플레이어 게임오브젝트 비활성화 검사
	if (list_Player.size() >= 1)
	{
		for (int i = 0; i < list_Player.size(); i++)
		{
			if (!list_Player[i]->getActive())
			{
				if (i == list_Player.size())
					break;
				tempO = list_Player[i];
				list_Player[i] = list_Player[i + 1];
				list_Player[i + 1] = tempO;
			}
		}
		if (!list_Player[list_Player.size() - 1]->getActive())
			list_Player.pop_back();
	}

	// 적 게임오브젝트 비활성화 검사
	if (list_Enemy.size() >= 1)
	{
		for (int i = 0; i < list_Enemy.size(); i++)
		{
			if (!list_Enemy[i]->getActive())
			{
				if (i == list_Enemy.size() - 1)
					break;
				tempO = list_Enemy[i];
				list_Enemy[i] = list_Enemy[i + 1];
				list_Enemy[i + 1] = tempO;
			}
		}
		if (!list_Enemy[list_Enemy.size() - 1]->getActive())
			list_Enemy.pop_back();
	}

	// 총알 게임오브젝트 비활성화 검사
	if (list_Bullet.size() >= 1)
	{
		for (int i = 0; i < list_Bullet.size(); i++)
		{
			if (!list_Bullet[i]->getActive())
			{
				if (i == list_Bullet.size() - 1)
					break;
				tempO = list_Bullet[i];
				list_Bullet[i] = list_Bullet[i + 1];
				list_Bullet[i + 1] = tempO;
			}
		}
		if (!list_Bullet[list_Bullet.size() - 1]->getActive())
			list_Bullet.pop_back();
	}

	// 모든 게임 오브젝트 비활성화 검사
	if (m_gameObjects.size() >= 1)
	{
		for (int i = 0; i < m_gameObjects.size(); i++)
		{
			if (!m_gameObjects[i]->getActive())
			{
				if (i == m_gameObjects.size() - 1)
					break;
				tempO = m_gameObjects[i];
				m_gameObjects[i] = m_gameObjects[i + 1];
				m_gameObjects[i + 1] = tempO;
			}
		}
		if (!m_gameObjects[m_gameObjects.size() - 1]->getActive())
			m_gameObjects.pop_back();
	}
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().GetX();
	rightA = p1->getPosition().GetX() + p1->getWidth();
	topA = p1->getPosition().GetY();
	bottomA = p1->getPosition().GetY() + p1->getHeight();

	//Calculate the sides of rect B
	leftB = p2->getPosition().GetX();
	rightB = p2->getPosition().GetX() + p2->getWidth();
	topB = p2->getPosition().GetY();
	bottomB = p2->getPosition().GetY() + p2->getHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}
