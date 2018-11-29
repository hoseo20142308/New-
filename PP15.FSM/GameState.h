#pragma once

#include "GameObject.h"
#include <string>
#include <vector>



class GameState
{
protected:
	vector<GameObject*> m_gameObjects;
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	virtual std::string getStateID() const = 0;
};
