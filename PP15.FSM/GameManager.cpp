#include "GameManager.h"
#include <cstdlib>
#include <ctime>
#include <random>
#include "Enemy.h"

GameManager* GameManager::s_pInstance = 0;

GameManager::GameManager()
{
	startTime = SDL_GetTicks();
}

void GameManager::Enemy_1_Spawn()
{	
	if ((Timer - startTime) > delay_Enemy_1_Spawn)
	{
		Vector2D Pos = setRandomPos();
		startTime = SDL_GetTicks();
		GameObject* enemy = new Enemy(new LoaderParams(Pos.GetX(), Pos.GetY(), 128, 55, 50, 30, "helicopter2"));

		PlayState::Instance()->m_gameObjects.push_back(enemy);
		PlayState::Instance()->list_Enemy.push_back(enemy);
	}

}

void GameManager::Enemy_2_Spawn()
{
	Vector2D Pos = setRandomPos();
}

int GameManager::getRandomNumber(int min, int max)
{
	random_device rn;
	mt19937_64 rnd(rn());

	uniform_int_distribution<int> range(min, max);

	return range(rnd);
}

/*int GameManager::getRandomNumber(float min, float max)
{
	random_device rn;
	mt19937_64 rnd(rn());

	uniform_int_distribution<float> range(min, max);

	return range(rnd);
}*/

Vector2D GameManager::setRandomPos()
{
	int num;
	int posX, posY;
	num = getRandomNumber(1, 4);
	switch (num)
	{
	case 1:
		posX = getRandomNumber(-200, -50);
		posY = getRandomNumber(-100, 550);
		break;
	case 2:
		posX = getRandomNumber(-200, 840);
		posY = getRandomNumber(-100, -50);
		break;
	case 3:
		posX = getRandomNumber(-200, 840);
		posY = getRandomNumber(480, 550);
		break;
	case 4:
		posX = getRandomNumber(640, 840);
		posY = getRandomNumber(-100, 550);
		break;
	default:
		break;
	}
	Vector2D position(posX, posY);

	return position;
}

void GameManager::update()
{
	Timer = SDL_GetTicks();

	Enemy_1_Spawn();
	//Enemy_2_Spawn();
}

GameManager * GameManager::Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new GameManager();
		return s_pInstance;
	}
	return s_pInstance;
}


