#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Ball.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* p_Params);
	virtual void draw();
	virtual void update();
	virtual void clean() {};

private:
	void handleInput();
	void shoot();					// 공을 쏠 때 사용할 함수
	const float shootRate = 500.0f;	// 공 발사 속도
	Uint32 inputTime;				// 공 발사시 입력 시간
	Uint32 shootTime = 0.0f;		// 공 발사시 시간
};