#include "Player.h"
#include "PlayState.h"
#include "Bullet.h"



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

	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));

	
	SDLGameObject::update();
}

void Player::handleInput()
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