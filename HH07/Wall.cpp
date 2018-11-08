#include "Wall.h"
#include "Game.h"

Wall::Wall(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Wall::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Wall::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);

	setRect();
	CheckAllBalls();

	//m_currentFrame = int(((SDL_GetTicks() / 100) % 1));


	SDLGameObject::update();
}

void Wall::setRect()
{
	rect.x = m_position.GetX();
	rect.y = m_position.GetY();
	rect.w = m_width;
	rect.h = m_height;
}

void Wall::CheckAllBalls()
{
	for (std::vector<Ball*>::size_type i = 0; i != TheGame::Instance()->Balls.size(); i++)
	{
		
		if (checkCollision( TheGame::Instance()->Balls[i]->getRect(), rect))
		{
			HP -= TheGame::Instance()->Balls[i]->getAtk();
			Ball* tempBall = TheGame::Instance()->Balls[i];
			TheGame::Instance()->Balls.pop_back();
			TheGame::Instance()->m_gameObjects.pop_back();
			delete(tempBall);
			
		}
	}
}

bool Wall::checkCollision(SDL_Rect rect1, SDL_Rect rect2)
{
	//The sides of the rectangles 
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A 
	leftA = rect1.x;
	rightA = rect1.x + rect1.w;
	topA = rect1.y;
	bottomA = rect1.y + rect1.h;

	//Calculate the sides of rect B 
	leftB = rect2.x;
	rightB = rect2.x + rect2.w;
	topB = rect2.y;
	bottomB = rect2.y + rect2.h;

	//If any of the sides from A are outside of B 
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B 
	return true;
}
