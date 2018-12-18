#pragma once
#include "GameState.h"
#include <vector>
class GameStateMachine
{
public:
	GameStateMachine();
	~GameStateMachine();

	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();

private:
	std::vector<GameState*> m_gameStates;
};

