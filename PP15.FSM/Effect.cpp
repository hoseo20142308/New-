#include "Effect.h"

const int EFFECT_SPEED = 60;

Effect::Effect(const LoaderParams * pParams, int num_frame, bool loop) : SDLGameObject(pParams)
{
	m_currentFrame = 1;
	m_numFrames = num_frame;
	isLoop = loop;
	startTime = SDL_GetTicks();
}

void Effect::update()
{
	checkTime = SDL_GetTicks();
	if (checkTime - startTime > EFFECT_SPEED)
	{
		startTime = SDL_GetTicks();
		m_currentFrame++;
	}
	endCheck();
}

void Effect::endCheck()
{
	if (m_currentFrame >= m_numFrames)
	{
		this->setActive(false);
	}
}


