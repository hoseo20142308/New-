#pragma once

#include "PlayState.h"

class GameManager
{
public:
	
	void update();

	static GameManager* Instance();
private:
	GameManager();
	static GameManager* s_pInstance;

	Uint32 spawnTime1, spawnTime2, Timer;
	float delay_Enemy_1_Spawn = 3000.0f;
	float delay_Enemy_2_Spawn = 10000.0f;

	void Enemy_1_Spawn();
	void Enemy_2_Spawn();

	int getRandomNumber(int min, int max);
	//int getRandomNumber(float min, float max);

	Vector2D setRandomPos();
};

