#include "Monster.h"

void Monster::load(int x, int y, int width, int height,
	std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
	// 이 코드가 의미가 있을까? 이코드가 없었다면, 자동으로 부모 호출?? 
}

void Monster::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
	// 이 코드가 의미가 있을까? 이코드가 없었다면, 자동으로 부모 호출?? 
}

void Monster::update()
{
	m_x -= 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}