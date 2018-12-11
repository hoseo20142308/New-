#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* p_Params);
	virtual void draw();
	virtual void update();
	virtual void clean() {};
private:
	Uint32 inputTime, shootTime;
	float delay_Shoot = 200.0f;
	void handleInput();
	void shoot();
};