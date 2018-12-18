
#include "Game.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "MenuState.h"
#include "PlayState.h"
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
					255, 0, 0, 255);
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
	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MenuState());
	TheInputHandler::Instance()->initialiseJoysticks();
	TextureManager::Instance()->load("assets/animate-alpha.png",
		"animate", m_pRenderer);

	//new Enemy(new LoaderParams(100, 100, 128, 82,
	//	"animate"));
	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82,
	                                       "animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(300, 100, 128, 82,
		"animate")));


	m_bRunning = true;
	return true;

}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color

	for (std::vector<GameObject*>::size_type i = 0; i !=
		m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
		
	}

	SDL_RenderPresent(m_pRenderer); 
}
void Game::update()
{

	for (std::vector<GameObject*>::size_type i = 0; i !=
		m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	
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

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_J))
	{
		m_pGameStateMachine->changeState(new PlayState());
	}
}
