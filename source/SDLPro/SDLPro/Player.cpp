#include "Player.h"
#include "SDL.h"
#include "InputHandler.h"
Player::Player()	
{
}

void Player::load(const LoaderParams *pParams)
{
	SDLGameObject::load(pParams);
}

void Player::draw()
{
	SDLGameObject::draw();
}
void Player::update()
{
	//if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	//{
	//	m_velocity.setX(1);
	//}

	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 50;


	//if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	//{
	//	m_velocity.setX(2);
	//}
	//if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	//{
	//	m_velocity.setX(-2);
	//}
	//if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	//{
	//	m_velocity.setY(-2);
	//}
	//if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	//{
	//	m_velocity.setY(2);
	//}


	//m_position.setX(m_position.getX() - 1);
	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));
	//m_acceleration.setX(1);
	SDLGameObject::update();
}
void Player::clean()
{
}

Player::~Player()
{
}
