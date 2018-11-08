#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"

class Ball : public SDLGameObject
{
public:
	Ball(const LoaderParams* p_Params);
	virtual void draw();
	virtual void update();
	virtual void clean() {};
	int getAtk() { return attackPoint; }
	SDL_Rect getRect() { return rect; }

private:
	

	const int attackPoint = 3;
	SDL_Rect rect;

	void setRect();
	
};

