#pragma once

#include "SDLGameObject.h"

class Ball : public SDLGameObject
{
public:
	Ball(const LoaderParams* p_Params);
	virtual void draw();
	virtual void update();
	virtual void clean() {};
	int getAtk() { return attackPoint; }
	SDL_Rect getRect() { return rect; }
	void SetShown(bool shown) { IsShown = shown; }
	bool GetShown() { return IsShown; }

private:
	
	bool IsShown = true;		// �� �� ������ ���� ������ �ʺ��̰� �� ������ ������ �� ����
	const int attackPoint = 3;	// ���ݷ�
	SDL_Rect rect;				// �浹üũ�� ���� Rect��

	void setRect();			// �����϶� ���� �ٲ�� Rect���� �����ϱ� ���� �Լ�
};

