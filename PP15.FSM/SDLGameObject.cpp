
#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams),
m_position(pParams->getX(), pParams->getY()),
m_velocity(0.0f, 0.0f), m_acceleration(0.0f, 0.0f)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_dst_width = pParams->getDstWidth();
	m_dst_height = pParams->getDstHeight();

	m_textureID = pParams->getTextureID();
	m_currentRow = 1;
	m_currentFrame = 0;
}

void SDLGameObject::draw()
{
	/*TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.GetX(), (int)m_position.GetY(),
		m_width, m_height, m_currentRow, m_currentFrame,
		TheGame::Instance()->getRenderer());*/

	if (m_velocity.GetX() > 0)
	{
		TextureManager::Instance()->drawFrame(m_textureID,
			(Uint32)m_position.GetX(), (Uint32)m_position.GetY(),
			m_width, m_height, m_dst_width, m_dst_height, m_currentRow, m_currentFrame,
			TheGame::Instance()->getRenderer(),
			SDL_FLIP_HORIZONTAL);
	}
	else 
	{
		TextureManager::Instance()->drawFrame(m_textureID,
			(Uint32)m_position.GetX(), (Uint32)m_position.GetY(),
			m_width, m_height, m_dst_width, m_dst_height, m_currentRow, m_currentFrame,
			TheGame::Instance()->getRenderer());
	}

}

void SDLGameObject::update()
{
	m_velocity += m_acceleration;
	m_position += m_velocity;
}

void SDLGameObject::clean()
{
}


