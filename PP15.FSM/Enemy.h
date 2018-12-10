#pragma once

#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean() {};
private:
	int HP = 3;
	void checkCollision_to_Bullet();
	bool checkCollision(SDLGameObject* coll);
	void dead();

};