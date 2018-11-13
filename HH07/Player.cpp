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
	inputTime = SDL_GetTicks();		// �Է� ���� ���� �ð�
	
	if (inputTime - shootTime > shootRate)	// �Է� �� �ð� - �߻� �� �ð� > ���ݼӵ� �϶�
	{	
		Ball* tempBall = new Ball(new LoaderParams(m_position.GetX() + 100, m_position.GetY(),
									128, 128, "ball"));
		
		TheGame::Instance()->createGameObject_ball( tempBall );		// ���ӿ�����Ʈ�� GameŬ������ m_GameObjects�� �߰�
		TheGame::Instance()->Balls.push_back(tempBall);
		shootTime = SDL_GetTicks();	// �߻� ���� ���� �ð�
	}
}
