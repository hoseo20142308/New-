#include "Ball.h"

Ball::Ball(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Ball::draw()
{
	// false��� ������ �ʰ� ������
	if (IsShown)
	{
		SDLGameObject::draw(); // we now use SDLGameObject
	}
}
void Ball::update()
{
	// ���� ���������� ������ �ӵ��� �����δ�.
	m_velocity.setX(10);
	m_velocity.setY(0);
	

	m_currentFrame = 0;

	// ��ġ�� �ٲ�� ���� ��Ʈ���� �� ����
	setRect();


	SDLGameObject::update();
}

void Ball::setRect()
{
	// �̹��� ���Ͽ��� ����� ������ ���� ��ġ�� ����
	rect.x = m_position.GetX() + 39;
	rect.y = m_position.GetY() + 44;
	// �̹��� ���Ͽ��� ���� ũ�⸦ ����
	rect.w = 40;
	rect.h = 40;
}
