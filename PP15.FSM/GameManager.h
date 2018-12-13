#pragma once

#include "PlayState.h"

class GameManager
{
public:
	
	void update();

	static GameManager* Instance();

	void Init();

	// 게임오버 처리 관련 변수 및 함수

	Uint32 deadTime, deadTimer;
	float delay_Enter_GameOverState = 3000.0f;

	void check_GameOver();

private:
	GameManager();
	static GameManager* s_pInstance;

	// 적 스폰 관련 변수 및 함수

	Uint32 spawnTime1, spawnTime2, Timer;
	float delay_Enemy_1_Spawn = 3000.0f;
	float delay_Enemy_2_Spawn = 10000.0f;

	void Enemy_1_Spawn();
	void Enemy_2_Spawn();

	int getRandomNumber(int min, int max);
	//int getRandomNumber(float min, float max);

	Vector2D setRandomPos();
};

