#pragma once

#include "GameObject.h"
#include "GameState.h"

class PauseState : public GameState
{
public:
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_pauseID; }
private:
	static void s_pauseToMain();
	static void s_resumePlay();
	static const std::string s_pauseID;
};

