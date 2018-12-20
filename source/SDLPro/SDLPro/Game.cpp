
#include "Game.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "MenuState.h"
#include "PlayState.h"
#include "GameObjectFactory.h"
#include "MenuButtonCreator.h"
#include "PlayerCreator.h"
#include "MainMenuState.h"
#include "EnemyCreator.h"
#include "AnimatedGraphicCreator.h"
Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	if (SDL_Init(SDL_INIT_EVENTS) == 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0)
			{
				SDL_SetRenderDrawColor(m_pRenderer,
					0, 0, 0, 255);
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	TheGameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
	TheGameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
	TheGameObjectFactory::Instance()->registerType("Enemy", new EnemyCreator());
	TheGameObjectFactory::Instance()->registerType("AnimatedGraphic", new AnimatedGraphicCreator());
	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MainMenuState());
	m_bRunning = true;
	return true;

}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color

	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer); 
}
void Game::update()
{
	m_pGameStateMachine->update();		
}

void Game::clean()
{
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();

}
