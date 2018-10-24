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

Monster::Monster(int spd, int cycledst, int fspd)	// 생성자
{
	state = RIGHT;			// 시작시 오른쪽 이동 상태
	speed = spd;			// 객체 스피드 값 설정
	distCycle = cycledst;	// 객체 좌우 반복 이동 값 설정
	frameSpeed = fspd;		// 프레임 속도 설정
	movementValue = 0;		// 이동한 거리 0으로 초기화
}

bool Monster::isTurn()		// 방향전환 확인 함수
{
	if (movementValue >= distCycle)	// 이동한 거리가 설정한 이동 거리에 도달하면,
	{
		movementValue = 0;			// 이동한 거리를 초기화 하고
		return true;				// true 반환
	}
	else
		return false;				// 아니라면 false 반환
}

void Monster::Turn()			// 방향전환 실행 함수
{
	if (isTurn())				// 위에서 확인한 방향전환 여부가 true일때
	{
		switch (state)			// 현재 상태(오른쪽, 왼쪽)에 따라 다르게 설정한다. 
		{
		case Monster::RIGHT:	// 오른쪽으로 이동하는 상태였다면
			load(m_x, m_y, m_width, m_height, "animate_left");  // 왼쪽으로 이동하는 이미지로 바꿔준후
			setState(LEFT);		// 상태를 왼쪽으로 변경한다. 
			break;
		case Monster::LEFT:		// 왼쪽으로 이동하는 상태였다면				
			load(m_x, m_y, m_width, m_height, "animate_right"); // 오른쪽으로 이동하는 이미지로 바꿔준 후
			setState(RIGHT);	// 상태를 오른쪽으로 변경한다.
			break;
		}

	}
}

void Monster::Move()	// 객체의 이동을 담당할 함수
{
	switch (state)		// 상태에 따라 다르게 위치를 이동한다.
	{
	case Monster::RIGHT:		// 오른쪽 이동 상태라면
		m_x += speed;			// 이동속도 변수 만큼 오른쪽(+)으로 이동
		movementValue += speed;	// 이동한 거리 변수도 똑같이 증가
		break;
	case Monster::LEFT:			// 왼쪽 이동 상태라면
		m_x -= speed;			// 이동속도 변수 만큼 왼쪽(-)으로 이동
		movementValue += speed; // 이동한 거리 변수도 똑같이 증가
		break;
	}

	m_currentFrame = int(((SDL_GetTicks() / frameSpeed) % 6));	// 프레임 변환 속도 변수 활용하여 
																// 속도를 다르게 객체마다 다르게 줄수 있음
}