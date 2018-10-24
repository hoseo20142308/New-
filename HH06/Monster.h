#pragma once

#include "GameObject.h"

class Monster : public GameObject
{
	enum State	// 상태를 나타낼 enum
	{
		RIGHT,
		LEFT
	};

public:
	Monster(int spd, int cycledst, int fspd );	// 생성자 * 객체 생성시 이동속도와, 이동거리, 
												// 애니메이션 프레임 속도를 다르게 하기 위함

	void load(int x, int y, int width, int height,
		std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();

private:
	State state;				// 오브젝트의 현재 상태를 나타낼 열거형 변수 
								// * 좌우 상태에 따른 오브젝트 위치 이동과 그에 맞춰 이미지를 바꿔주기 위함

	int speed;					// 속도
	int movementValue;			// 이동한 거리
	int distCycle;				// 좌우 반복 이동할 거리
	int frameSpeed;				// 애니메이션의 속도

	bool isTurn();				// 방향 전환시 사용할 변수

	void setState(State state) { this->state = state; };	// 상태 설정 함수

	void Turn();				// 좌우 방향 전환 함수

	void Move();				// 좌우 이동 함수

};