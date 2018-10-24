#pragma once

#include "GameObject.h"

class Monster : public GameObject
{
	enum State	// ���¸� ��Ÿ�� enum
	{
		RIGHT,
		LEFT
	};

public:
	Monster(int spd, int cycledst, int fspd );	// ������ * ��ü ������ �̵��ӵ���, �̵��Ÿ�, 
												// �ִϸ��̼� ������ �ӵ��� �ٸ��� �ϱ� ����

	void load(int x, int y, int width, int height,
		std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();

private:
	State state;				// ������Ʈ�� ���� ���¸� ��Ÿ�� ������ ���� 
								// * �¿� ���¿� ���� ������Ʈ ��ġ �̵��� �׿� ���� �̹����� �ٲ��ֱ� ����

	int speed;					// �ӵ�
	int movementValue;			// �̵��� �Ÿ�
	int distCycle;				// �¿� �ݺ� �̵��� �Ÿ�
	int frameSpeed;				// �ִϸ��̼��� �ӵ�

	bool isTurn();				// ���� ��ȯ�� ����� ����

	void setState(State state) { this->state = state; };	// ���� ���� �Լ�

	void Turn();				// �¿� ���� ��ȯ �Լ�

	void Move();				// �¿� �̵� �Լ�

};