#include "Bullet.h"
#include "InputHandler.h"

Bullet::Bullet(const LoaderParams * pParams) : SDLGameObject(pParams)
{
	Vector2D* target = TheInputHandler::Instance()->GetMousePosition();
	m_velocity = *target - m_position;
	m_velocity.normalize();
	m_velocity *= 8;
}

void Bullet::update()
{
	mapoutCheck();

	SDLGameObject::update();
}

void Bullet::mapoutCheck()
{
	if ((m_position.GetX() < -50
		|| m_position.GetX() > 650) &&
		(m_position.GetY() < -50
			|| m_position.GetY() > 490))
		active = false;
}
