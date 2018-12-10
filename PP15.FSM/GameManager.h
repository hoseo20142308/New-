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

	Uint32 startTime, Timer;
	float delay_Enemy_1_Spawn = 1000.0f;
	float delay_Enemy_2_Spawn = 5000.0f;

	void Enemy_1_Spawn();
	void Enemy_2_Spawn();

	int getRandomNumber(int min, int max);
	//int getRandomNumber(float min, float max);

	Vector2D setRandomPos();
};

