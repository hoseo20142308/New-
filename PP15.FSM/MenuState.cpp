#include "MenuState.h"
#include "PlayState.h"
#include "Game.h"
#include "MenuButton.h"
#include <iostream>

const std::string MenuState::s_menuID = "MENU";

MenuState* MenuState::s_pInstance = 0;

void MenuState::update()
{
	// nothing for now
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	// nothing for now
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/button.png", "playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/exit.png", "exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 400, 100, "playbutton"), s_menuToPlay);
	GameObject* button2 = new MenuButton(new LoaderParams(100, 300, 400, 100, "exitbutton"), s_exitFromMenu);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");

	std::cout << "exiting MenuState\n";
	return true;
}

MenuState * MenuState::Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new MenuState();

		return s_pInstance;
	}
	return s_pInstance;
}

void MenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
	std::cout << "Play button clicked" << endl;
}

void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
	std::cout << "Exit button clicked" << endl;
}
