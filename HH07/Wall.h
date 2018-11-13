#pragma once

#include "SDLGameObject.h"

class Wall : public SDLGameObject
{
public:
	Wall(const LoaderParams* p_Params);
	virtual void draw();
	virtual void update();
	virtual void clean() {};

	void setShown(bool shown) { IsShown = shown; }
	bool getShown() { return IsShown; }

private:
	bool IsShown = true;	// ���̰ų�, �ʺ��̰� �ϱ� ���� ����
	int HP = 30;
	SDL_Rect rect;
	void setRect();			// ��Ʈ�� ���� �Լ�
	void CheckAllBalls();	// ��� ���� �浹üũ�ϱ� ���� �Լ�
	bool checkCollision(SDL_Rect rect1, SDL_Rect rect2);	// �浹üũ �˻� �Լ�
	void checkHP();			// HP�� ���� �̹��� ��ȭ �Լ�
};

