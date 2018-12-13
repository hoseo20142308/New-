#include "Enemy.h"
#include "PlayState.h"
#include "Player.h"

Enemy::Enemy(const LoaderParams* pParams, int type) : SDLGameObject(pParams)
{
	e_Type = type;
	m_numFrames = 5;
	if (PlayState::Instance()->list_Player.size() >= 1)
	{
		tempPlayer = dynamic_cast<SDLGameObject*>(PlayState::Instance()->list_Player[0]);
		m_velocity = tempPlayer->getPosition() - m_position;
		m_velocity.normalize();
		m_velocity *= 5;
	}
}
void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));

	trace();

	checkCollision_to_Bullet();

	mapoutCheck();

	dead();

	SDLGameObject::update();

}

void Enemy::checkCollision_to_Bullet()
{
	for (int i = 0; i < PlayState::Instance()->list_Bullet.size(); i++)
	{
		if (checkCollision(dynamic_cast<SDLGameObject*>(PlayState::Instance()->list_Bullet[i])))
		{
			std::cout << "CollisionCheck.Enemy_to_Bullet\n";
			PlayState::Instance()->list_Bullet[i]->setActive(false);
			HP--;
		}
	}
}

bool Enemy::checkCollision(SDLGameObject * coll)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = m_position.GetX();
	rightA = m_position.GetX() + m_dst_width;
	topA = m_position.GetY();
	bottomA = m_position.GetY() + m_dst_height;

	//Calculate the sides of rect B
	leftB = coll->getPosition().GetX();
	rightB = coll->getPosition().GetX() + coll->getWidth();
	topB = coll->getPosition().GetY();
	bottomB = coll->getPosition().GetY() + coll->getHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}

void Enemy::dead()
{
	if (HP <= 0)
	{
		active = false;

		cout << "enemy dead!\n";
	}
}

void Enemy::mapoutCheck()
{
	if ((m_position.GetX() < -300
		|| m_position.GetX() > 1000) &&
		(m_position.GetY() < -300
			|| m_position.GetY() > 1000))
		active = false;
}

void Enemy::trace()
{
	if (e_Type == 2)
	{
		if (PlayState::Instance()->list_Player.size() >= 1)
		{
			tempPlayer = dynamic_cast<SDLGameObject*>(PlayState::Instance()->list_Player[0]);
			m_velocity = tempPlayer->getPosition() - m_position;
			m_velocity.normalize();
			m_velocity *= 5;
		}
	}
}
