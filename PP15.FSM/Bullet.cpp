#include "Bullet.h"
#include "InputHandler.h"

Bullet::Bullet(const LoaderParams * pParams) : SDLGameObject(pParams)
{
	Vector2D* target = TheInputHandler::Instance()->GetMousePosition();
	m_velocity = *target - m_position;
	m_velocity.normalize();
	m_velocity *= 5;
}
