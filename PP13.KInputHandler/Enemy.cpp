#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
	m_position.setX(m_position.GetX() + 1);
	m_position.setY(m_position.GetY() + 1);

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}