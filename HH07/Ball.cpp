#include "Ball.h"

Ball::Ball(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Ball::draw()
{
	// false라면 보이지 않게 설정함
	if (IsShown)
	{
		SDLGameObject::draw(); // we now use SDLGameObject
	}
}
void Ball::update()
{
	// 공은 오른쪽으로 일정한 속도로 움직인다.
	m_velocity.setX(10);
	m_velocity.setY(0);
	

	m_currentFrame = 0;

	// 위치가 바뀌고 나면 렉트값을 재 설정
	setRect();


	SDLGameObject::update();
}

void Ball::setRect()
{
	// 이미지 파일에서 빈곳을 제외한 공의 위치를 설정
	rect.x = m_position.GetX() + 39;
	rect.y = m_position.GetY() + 44;
	// 이미지 파일에서 공의 크기를 설정
	rect.w = 40;
	rect.h = 40;
}
