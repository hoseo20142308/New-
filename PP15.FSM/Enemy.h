#pragma once

#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams, int type);
	virtual void draw();
	virtual void update();
	virtual void clean() {};
private:
	int e_Type;
	int HP = 3;
	SDLGameObject* tempPlayer;
	void checkCollision_to_Bullet();
	bool checkCollision(SDLGameObject* coll);
	void dead();
	void mapoutCheck();
	void trace();

};