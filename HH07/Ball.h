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
	
	bool IsShown = true;		// 불 형 변수로 보일 것인지 않보이게 할 것인지 설정할 수 있음
	const int attackPoint = 3;	// 공격력
	SDL_Rect rect;				// 충돌체크를 위한 Rect값

	void setRect();			// 움직일때 마다 바뀌는 Rect값을 설정하기 위한 함수
};

