#include "Monster.h"

void Monster::load(int x, int y, int width, int height,
	std::string textureID)
{
	GameObject::load(x, y, width, height, textureID); 
}

void Monster::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);	
}

void Monster::update()
{
	Move();
	Turn();
}

Monster::Monster(int spd, int cycledst, int fspd)	// ������
{
	state = RIGHT;			// ���۽� ������ �̵� ����
	speed = spd;			// ��ü ���ǵ� �� ����
	distCycle = cycledst;	// ��ü �¿� �ݺ� �̵� �� ����
	frameSpeed = fspd;		// ������ �ӵ� ����
	movementValue = 0;		// �̵��� �Ÿ� 0���� �ʱ�ȭ
}

bool Monster::isTurn()		// ������ȯ Ȯ�� �Լ�
{
	if (movementValue >= distCycle)	// �̵��� �Ÿ��� ������ �̵� �Ÿ��� �����ϸ�,
	{
		movementValue = 0;			// �̵��� �Ÿ��� �ʱ�ȭ �ϰ�
		return true;				// true ��ȯ
	}
	else
		return false;				// �ƴ϶�� false ��ȯ
}

void Monster::Turn()			// ������ȯ ���� �Լ�
{
	if (isTurn())				// ������ Ȯ���� ������ȯ ���ΰ� true�϶�
	{
		switch (state)			// ���� ����(������, ����)�� ���� �ٸ��� �����Ѵ�. 
		{
		case Monster::RIGHT:	// ���������� �̵��ϴ� ���¿��ٸ�
			load(m_x, m_y, m_width, m_height, "animate_left");  // �������� �̵��ϴ� �̹����� �ٲ�����
			setState(LEFT);		// ���¸� �������� �����Ѵ�. 
			break;
		case Monster::LEFT:		// �������� �̵��ϴ� ���¿��ٸ�				
			load(m_x, m_y, m_width, m_height, "animate_right"); // ���������� �̵��ϴ� �̹����� �ٲ��� ��
			setState(RIGHT);	// ���¸� ���������� �����Ѵ�.
			break;
		}

	}
}

void Monster::Move()	// ��ü�� �̵��� ����� �Լ�
{
	switch (state)		// ���¿� ���� �ٸ��� ��ġ�� �̵��Ѵ�.
	{
	case Monster::RIGHT:		// ������ �̵� ���¶��
		m_x += speed;			// �̵��ӵ� ���� ��ŭ ������(+)���� �̵�
		movementValue += speed;	// �̵��� �Ÿ� ������ �Ȱ��� ����
		break;
	case Monster::LEFT:			// ���� �̵� ���¶��
		m_x -= speed;			// �̵��ӵ� ���� ��ŭ ����(-)���� �̵�
		movementValue += speed; // �̵��� �Ÿ� ������ �Ȱ��� ����
		break;
	}

	m_currentFrame = int(((SDL_GetTicks() / frameSpeed) % 6));	// ������ ��ȯ �ӵ� ���� Ȱ���Ͽ� 
																// �ӵ��� �ٸ��� ��ü���� �ٸ��� �ټ� ����
}