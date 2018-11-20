#pragma once

#include "GameState.h"

class GameStateMachine
{
public:
	void changeState(GameState* pState);
	void popState();
private:
	GameState* m_currentState;
	GameState* m_prevState;
};

