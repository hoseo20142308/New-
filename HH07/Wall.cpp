#include "Wall.h"
#include "Game.h"

Wall::Wall(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Wall::draw()
{
	if (IsShown)
	{
		SDLGameObject::draw(); // we now use SDLGameObject
	}
}

void Wall::update()
{
	// ���� �������� �ʴ´�.
	m_velocity.setX(0);
	m_velocity.setY(0);


	setRect();			// Rect �� ����
	CheckAllBalls();	// ��� ���� �浹üũ �˻�
	checkHP();			// HP�� ���� �̹��� ��ȭ


	SDLGameObject::update();
}

void Wall::setRect()
{
	rect.x = m_position.GetX() + 47;	// �̹��� ���Ͽ��� ���� �����ϴ� ��ġ x
	rect.y = m_position.GetY() + 27;	// �̹��� ���Ͽ��� ���� �����ϴ� ��ġ y
	rect.w = 40;	// ���� ũ�� x
	rect.h = 66;	// ���� ũ�� y
}

void Wall::CheckAllBalls()
{
	for (std::vector<Ball*>::size_type i = 0; i != TheGame::Instance()->Balls.size(); i++)
	{
		bool isactive = TheGame::Instance()->Balls[i]->GetShown();	// ���� Ȱ��ȭ ���� = ���̴� ���� = �浹üũ �Ҽ� �ִ� ����
		// ���� �� �Ѵ� ���̴� �����̸鼭 ���� ���� �ε����� ��
		if (isactive && IsShown && checkCollision(TheGame::Instance()->Balls[i]->getRect(), rect))	
		{
			HP -= TheGame::Instance()->Balls[i]->getAtk();	// ���� HP�� ���� ���ݷ� ��ŭ ����
			TheGame::Instance()->Balls[i]->SetShown(false);	// ���� ���¸� ������ �ʰ� ����		
		}
	}
}

bool Wall::checkCollision(SDL_Rect rect1, SDL_Rect rect2)
{
	// ���� �� ��Ʈ ���� ���� ��������  
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	// ù��° �浹ü (rect 1)�� ���� ���� ������ �Ҵ�
	leftA = rect1.x;
	rightA = rect1.x + rect1.w;
	topA = rect1.y;
	bottomA = rect1.y + rect1.h;

	// �ι�° �浹ü (rect 2)�� ���� ���� ������ �Ҵ� 
	leftB = rect2.x;
	rightB = rect2.x + rect2.w;
	topB = rect2.y;
	bottomB = rect2.y + rect2.h;

	// �浹�� �Ͼ�� ���� ��츦 ���� false�� ��ȯ
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	// ���� ��� ��츦 �������� ���� �� true�� ��ȯ
	return true;
}

void Wall::checkHP()
{
	// ü�¿� ���� ����
	if (HP >= 20) m_currentFrame = 0;					// 20 �̻��̸� ������ �̹���
	else if (HP < 20 && HP >= 10) m_currentFrame = 1;	// 20 �̸� 10 �̻��̸� ��¦ ���̰� �̹���
	else if (HP < 10 && HP >= 1) m_currentFrame = 2;	// 10 �̸� 1 �̻��̸� ���� ���̰� �̹���
	else if (HP <= 0) IsShown = false;					// 0 ���ϸ� ������ �ʰ� �����Ѵ�
}
