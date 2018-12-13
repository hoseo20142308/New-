#pragma once

#include "SDLGameObject.h"
#include "Game.h"

class Effect : public SDLGameObject
{
public:
	Effect(const LoaderParams* pParams, int num_frame, bool loop);
	//virtual void draw();
	virtual void update();
	virtual void clean() {};
private:
	bool isLoop;

	Uint32 startTime, checkTime;
	void endCheck();
};