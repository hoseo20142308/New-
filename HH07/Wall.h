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
	bool IsShown = true;	// 보이거나, 않보이게 하기 위한 변수
	int HP = 30;
	SDL_Rect rect;
	void setRect();			// 렉트값 설정 함수
	void CheckAllBalls();	// 모든 공과 충돌체크하기 위한 함수
	bool checkCollision(SDL_Rect rect1, SDL_Rect rect2);	// 충돌체크 검사 함수
	void checkHP();			// HP에 따른 이미지 변화 함수
};

