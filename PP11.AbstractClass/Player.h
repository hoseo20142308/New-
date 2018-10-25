#pragma once

#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* p_Params);
	virtual void draw();
	virtual void update();
	virtual void clean();
};