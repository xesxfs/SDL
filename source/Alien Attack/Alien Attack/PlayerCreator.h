#pragma once
#include "BaseCreator.h"
#include "Player.h"
class PlayerCreator :
	public BaseCreator
{
public:
	PlayerCreator();
	~PlayerCreator();

	GameObject* createGameObject() const
	{
		return new Player();
	}
};

