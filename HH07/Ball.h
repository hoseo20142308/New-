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
private:
	
};

