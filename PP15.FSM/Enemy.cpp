#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setX(0.001);
	m_velocity.setY(2);
}
void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
	//m_position.setX(m_position.GetX() + 1);
	//m_position.setY(m_position.GetY() + 1);
	//m_velocity.setX(0);
	//m_velocity.setY(0);

	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));
	if (m_position.GetY() < 0) 
	{
		m_velocity.setY(2);
	}
	else if (m_position.GetY() > 400) 
	{
		m_velocity.setY(-2);
	}
	SDLGameObject::update();
	
}

void Enemy::handleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState(InputHandler::LEFT))
	{
		m_velocity.setX(0);
	}

	Vector2D* vec = TheInputHandler::Instance()->GetMousePosition();
	m_velocity = (*vec - m_position) / 100;


}
