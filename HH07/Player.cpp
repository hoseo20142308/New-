#include "Player.h"
#include "Game.h"

//std::vector<SDLGameObject*> m_gameObjects = TheGame::Instance().;

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
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

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	
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
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z))
	{
		shoot();
	}
}

void Player::shoot()
{
	inputTime = SDL_GetTicks();		// 입력 했을 때의 시간
	
	if (inputTime - shootTime > shootRate)	// 입력 시 시간 - 발사 시 시간 > 공격속도 일때
	{	
		Ball* tempBall = new Ball(new LoaderParams(m_position.GetX() + 100, m_position.GetY(),
									128, 128, "ball"));
		
		TheGame::Instance()->createGameObject_ball( tempBall );		// 게임오브젝트를 Game클래스의 m_GameObjects에 추가
		TheGame::Instance()->Balls.push_back(tempBall);
		shootTime = SDL_GetTicks();	// 발사 했을 때의 시간
	}
}
