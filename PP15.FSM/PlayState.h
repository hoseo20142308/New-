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

	// 게임오브젝트 별 배열
	vector<GameObject*> list_Player;		// 플레이어 헬기 게임오브젝트 배열
	vector<GameObject*> list_Enemy;		// 적 헬기 게임오브젝트 배열
	vector<GameObject*> list_Bullet;		// 총알 게임오브젝트 배열

private:
	PlayState() {};
	static const std::string s_playID;
	static PlayState* s_pInstance;

	void pop_vector();

};

