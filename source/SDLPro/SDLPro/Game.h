
#ifndef __Game__
#define __Game__

#include "GameObject.h"
#include "SDL.h"
#include "LoaderParams.h"
#include <iostream>
#include <vector>
#include "GameStateMachine.h"
class Game
{
public:
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}


	//    GameObject* m_go;
	//    GameObject* m_player;
	//    GameObject* m_enemy;

	//std::vector<GameObject*> m_gameObjects;
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit() {
		m_bRunning = false;
	}
	SDL_Renderer* getRenderer() const
	{
		return m_pRenderer;
	}
	bool running()
	{
		return m_bRunning;
	}

	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

	int getGameWidth() const
	{
		return m_gameWidth;
	}
	int getGameHeight() const
	{
		return m_gameHeight;
	}

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	int m_currentFrame;
	GameStateMachine* m_pGameStateMachine;
	Game() {};
	static Game* s_pInstance;
	int m_gameWidth;
	int m_gameHeight;
};

typedef Game TheGame;

#endif // __Game__
