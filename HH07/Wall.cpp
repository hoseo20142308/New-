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
	// 벽은 움직이지 않는다.
	m_velocity.setX(0);
	m_velocity.setY(0);


	setRect();			// Rect 값 설정
	CheckAllBalls();	// 모든 공과 충돌체크 검사
	checkHP();			// HP에 따라 이미지 변화


	SDLGameObject::update();
}

void Wall::setRect()
{
	rect.x = m_position.GetX() + 47;	// 이미지 파일에서 벽이 시작하는 위치 x
	rect.y = m_position.GetY() + 27;	// 이미지 파일에서 벽이 시작하는 위치 y
	rect.w = 40;	// 벽의 크기 x
	rect.h = 66;	// 벽의 크기 y
}

void Wall::CheckAllBalls()
{
	for (std::vector<Ball*>::size_type i = 0; i != TheGame::Instance()->Balls.size(); i++)
	{
		bool isactive = TheGame::Instance()->Balls[i]->GetShown();	// 공의 활성화 상태 = 보이는 상태 = 충돌체크 할수 있는 상태
		// 공과 벽 둘다 보이는 상태이면서 공과 벽이 부딪혔을 때
		if (isactive && IsShown && checkCollision(TheGame::Instance()->Balls[i]->getRect(), rect))	
		{
			HP -= TheGame::Instance()->Balls[i]->getAtk();	// 벽의 HP를 공의 공격력 만큼 빼줌
			TheGame::Instance()->Balls[i]->SetShown(false);	// 공의 상태를 보이지 않게 설정		
		}
	}
}

bool Wall::checkCollision(SDL_Rect rect1, SDL_Rect rect2)
{
	// 각각 의 렉트 값에 따라 설정해줄  
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	// 첫번째 충돌체 (rect 1)의 값을 토대로 변수에 할당
	leftA = rect1.x;
	rightA = rect1.x + rect1.w;
	topA = rect1.y;
	bottomA = rect1.y + rect1.h;

	// 두번째 충돌체 (rect 2)의 값을 토대로 변수에 할당 
	leftB = rect2.x;
	rightB = rect2.x + rect2.w;
	topB = rect2.y;
	bottomB = rect2.y + rect2.h;

	// 충돌이 일어나지 않을 경우를 전부 false로 반환
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

	// 위의 모든 경우를 만족하지 않을 때 true를 반환
	return true;
}

void Wall::checkHP()
{
	// 체력에 따라 각각
	if (HP >= 20) m_currentFrame = 0;					// 20 이상이면 멀쩡한 이미지
	else if (HP < 20 && HP >= 10) m_currentFrame = 1;	// 20 미만 10 이상이면 살짝 금이간 이미지
	else if (HP < 10 && HP >= 1) m_currentFrame = 2;	// 10 미만 1 이상이면 많이 금이간 이미지
	else if (HP <= 0) IsShown = false;					// 0 이하면 보이지 않게 설정한다
}
