#include "Ball.h"

Ball::Ball(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Ball::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Ball::update()
{
	m_velocity.setX(1);
	m_velocity.setY(0);
	

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));


	SDLGameObject::update();
}

/*void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}
}*/
