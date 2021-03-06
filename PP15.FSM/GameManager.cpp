#include "GameManager.h"
#include <cstdlib>
#include <ctime>
#include <random>
#include "Enemy.h"
#include "Game.h"
#include "GameOverState.h"

GameManager* GameManager::s_pInstance = 0;

GameManager::GameManager()
{
	spawnTime1 = SDL_GetTicks();
	spawnTime2 = SDL_GetTicks();
}

void GameManager::Enemy_1_Spawn()
{	
	if ((Timer - spawnTime1) > delay_Enemy_1_Spawn)
	{
		Vector2D Pos = setRandomPos();
		spawnTime1 = SDL_GetTicks();
		GameObject* enemy = new Enemy(new LoaderParams(Pos.GetX(), Pos.GetY(), 128, 55, 60, 30, "helicopter2"), 1);

		PlayState::Instance()->m_gameObjects.push_back(enemy);
		PlayState::Instance()->list_Enemy.push_back(enemy);

		delay_Enemy_1_Spawn -= 100.0f;
		if (delay_Enemy_1_Spawn < 1000.0f) delay_Enemy_1_Spawn = 1000.0f;
	}

}

void GameManager::Enemy_2_Spawn()
{
	if ((Timer - spawnTime2) > delay_Enemy_2_Spawn)
	{
		Vector2D Pos = setRandomPos();
		spawnTime2 = SDL_GetTicks();
		GameObject* enemy = new Enemy(new LoaderParams(Pos.GetX(), Pos.GetY(), 128, 55, 60, 30, "helicopter3"), 2);

		PlayState::Instance()->m_gameObjects.push_back(enemy);
		PlayState::Instance()->list_Enemy.push_back(enemy);

		delay_Enemy_2_Spawn -= 50.0f;
		if (delay_Enemy_2_Spawn < 3000.0f) delay_Enemy_2_Spawn = 3000.0f;
	}
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

void GameManager::check_GameOver()
{
	if (PlayState::Instance()->list_Player.size() <= 0)
	{
		deadTimer = SDL_GetTicks();

		if (deadTimer - deadTime > delay_Enter_GameOverState)
		{
			TheGame::Instance()->Instance()->getStateMachine()->changeState(GameOverState::Instance());
		}
	}

	
}

void GameManager::update()
{
	Timer = SDL_GetTicks();

	Enemy_1_Spawn();
	Enemy_2_Spawn();

	check_GameOver();
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

void GameManager::Init()
{
	spawnTime1 = SDL_GetTicks();
	spawnTime2 = SDL_GetTicks();
}


