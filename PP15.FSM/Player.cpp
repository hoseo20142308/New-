#include "Player.h"
#include "PlayState.h"
#include "GameOverState.h"
#include "Bullet.h"
#include "Effect.h"
#include "Game.h"



Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	Player::shootTime = SDL_GetTicks();
}
void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput();	// add our function

	collisionCheck_to_Enemy();

	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));

	
	SDLGameObject::update();
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(speed);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-speed);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-speed);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(speed);
	}
	if (TheInputHandler::Instance()->getMouseButtonState(InputHandler::LEFT))
	{
			shoot();
	}

	//Vector2D* target = TheInputHandler::Instance()->GetMousePosition();
	//m_velocity = *target - m_position;
	//m_velocity /= 50;
}

void Player::shoot()
{
	inputTime = SDL_GetTicks();
	if (inputTime - shootTime > delay_Shoot)
	{
		GameObject* bullet = new Bullet(new LoaderParams(m_position.GetX() + m_dst_width / 2, m_position.GetY() + m_dst_height / 2, 12, 12, "bullet"));

		PlayState::Instance()->m_gameObjects.push_back(bullet);
		PlayState::Instance()->list_Bullet.push_back(bullet);
		shootTime = SDL_GetTicks();
	}
}

void Player::collisionCheck_to_Enemy()
{
	for (int i = 0; i < PlayState::Instance()->list_Enemy.size(); i++)
	{
		if (checkCollision(dynamic_cast<SDLGameObject*>(PlayState::Instance()->list_Enemy[i])))
		{
			std::cout << "CollisionCheck.Player_to_Enemy\n";
			this->setActive(false);
			GameObject* effect = new Effect(new LoaderParams(m_position.GetX() - 50, m_position.GetY() - 50, 192, 192, "explosion"), 12, false);
			PlayState::Instance()->m_gameObjects.push_back(effect);
		}
	}
}

bool Player::checkCollision(SDLGameObject * coll)
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
