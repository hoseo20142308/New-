#pragma once

#include "GameState.h"

class MenuState : public GameState
{
public:
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_menuID; }

	static MenuState* Instance();
private:
	MenuState() {};

	static void s_menuToPlay();
	static void s_exitFromMenu();

	static const std::string s_menuID;
	static MenuState* s_pInstance;

};

