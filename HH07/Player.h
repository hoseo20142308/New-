#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Ball.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* p_Params);
	virtual void draw();
	virtual void update();
	virtual void clean() {};

private:
	void handleInput();
	void shoot();					// ���� �� �� ����� �Լ�
	const float shootRate = 500.0f;	// �� �߻� �ӵ�
	Uint32 inputTime;				// �� �߻�� �Է� �ð�
	Uint32 shootTime = 0.0f;		// �� �߻�� �ð�
};