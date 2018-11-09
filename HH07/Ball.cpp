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
	m_velocity.setX(10);
	m_velocity.setY(0);
	

	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));

	setRect();


	SDLGameObject::update();
}

void Ball::setRect()
{
	rect.x = m_position.GetX();
	rect.y = m_position.GetY();
	rect.w = m_width;
	rect.h = m_height;
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
