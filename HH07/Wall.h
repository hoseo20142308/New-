#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Player.h"

class Wall : public SDLGameObject
{
public:
	Wall(const LoaderParams* p_Params);
	virtual void draw();
	virtual void update();
	virtual void clean() {};

private:
	int HP = 30;
	SDL_Rect rect;
	void setRect();
	void CheckAllBalls();
	bool checkCollision(SDL_Rect rect1, SDL_Rect rect2);
};

