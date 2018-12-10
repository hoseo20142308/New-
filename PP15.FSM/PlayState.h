#pragma once

#include "GameState.h"
#include "SDLGameObject.h"
#include "GameManager.h"

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }
	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);

	static PlayState* Instance();

	// ���ӿ�����Ʈ �� �迭
	vector<GameObject*> list_Player;		// �÷��̾� ��� ���ӿ�����Ʈ �迭
	vector<GameObject*> list_Enemy;		// �� ��� ���ӿ�����Ʈ �迭
	vector<GameObject*> list_Bullet;		// �Ѿ� ���ӿ�����Ʈ �迭

private:
	PlayState() {};
	static const std::string s_playID;
	static PlayState* s_pInstance;

	void pop_vector();

};

